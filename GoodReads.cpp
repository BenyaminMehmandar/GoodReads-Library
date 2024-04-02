#include "GoodReads.hpp"

#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

GoodReads::GoodReads(vector<Users> u, vector<Authors> a, vector<Books> b, vector<Reviews> r, vector<FollowEdges> f)
{
    users = u;
    authors = a;
    books = b;
    reviews = r;
    follow_edges = f;
}

Authors *GoodReads::find_author_by_id(int author_id)
{
    for (int i = 0; i < authors.size(); i++)
        if (authors[i].get_id() == author_id)
            return &authors[i];
}

Authors GoodReads::gen_author_info(int author_id)
{
    Authors *aut = find_author_by_id(author_id);
    return *aut;
}

void GoodReads::gen_book_id_and_title(int author_id)
{
   for(int i = 0; i < books.size(); ++i)
        if (books[i].get_author_id() == author_id)
            books[i].to_string();

}

vector<string> GoodReads::gen_shelf_books(int user_id, string shelf_type)
{
    for (int i = 0; i < users.size(); ++i)
        if(user_id == users[i].get_id())
        {
            if (shelf_type == "want_to_read")
                return users[i].get_want_to_read();
            else if (shelf_type == "currently_reading")
                return users[i].get_currently_reading();
            else if (shelf_type == "read")
                return users[i].get_read();
        }
}

vector<string> GoodReads::gen_same_genre_books(int user_id, string shelf_type, string genre)
{   
    vector<string> all_shelf_books = gen_shelf_books(user_id, shelf_type);
    vector<string> same_genre_books;
    for (int i = 0; i < all_shelf_books.size(); ++i)
        for (int j = 0; j < books.size(); ++j)
            if ((books[j].get_id() == stoi(all_shelf_books[i])) && (books[j].get_genre() == genre))
                same_genre_books.push_back(books[j].get_title());   
    return same_genre_books;
}

vector<string> GoodReads::gen_diff_genre_books(int user_id, string shelf_type, string genre)
{   
    vector<string> all_shelf_books = gen_shelf_books(user_id, shelf_type);
    vector<string> diff_genre_books;
    for (int i = 0; i < all_shelf_books.size(); ++i)
        for (int j = 0; j < books.size(); ++j)
            if ((books[j].get_id() == stoi(all_shelf_books[i])) && (books[j].get_genre() != genre))
                diff_genre_books.push_back(books[j].get_title());
    return diff_genre_books;
}

void GoodReads::print_all_shelf_books(int user_id, string shelf_type, string genre)
{
    vector<string> same_genre_books = gen_same_genre_books(user_id, shelf_type, genre);
    sort(same_genre_books.begin(), same_genre_books.end());
    vector<string> diff_genre_books = gen_diff_genre_books(user_id, shelf_type, genre);
    sort(diff_genre_books.begin(), diff_genre_books.end());
    for (int i = 0; i < same_genre_books.size(); ++i)
        for (int j = 0; j < books.size(); ++j)
            if (books[j].get_title() == same_genre_books[i])
            {
                books[j].print_book_info();
                cout << "Author: " << find_author_by_id(books[j].get_author_id())->get_name() << endl;
                cout << "***" << endl;
            }
    for (int i = 0; i < diff_genre_books.size(); ++i)
        for (int j = 0; j < books.size(); ++j)
            if (books[j].get_title() == diff_genre_books[i])
            {
                books[j].print_book_info();
                cout << "Author: " << find_author_by_id(books[j].get_author_id())->get_name() << endl;
                cout << "***" << endl;
            }
}


float GoodReads::compute_user_credit(int user_id)
{
    int number_of_user_reviews = 0;
    int number_of_reviews = reviews.size();
    int number_of_user_reviews_likes = 0;
    int number_of_likes = 0;
    for (int i = 0; i < reviews.size(); ++i)
    {
        number_of_likes = number_of_likes + reviews[i].get_number_of_likes();
        if (reviews[i].get_user_id() == user_id)
        {
            number_of_user_reviews_likes = number_of_user_reviews_likes + reviews[i].get_number_of_likes();
            number_of_user_reviews = number_of_user_reviews + 1;
        }
    }
    float credit = 0.5 * ((float(number_of_user_reviews_likes) / float(number_of_likes)) + (float(number_of_user_reviews) / float(number_of_reviews)));
    return credit;
}


float GoodReads::compute_book_score(int book_id)
{
    int sum_of_scores = 0;
    float average_score = 0;
    int num_of_reviews = 0;
    for (int i = 0; i < reviews.size(); ++i)
        if(reviews[i].get_book_id() == book_id)
        {
            num_of_reviews = num_of_reviews + 1;
            sum_of_scores = sum_of_scores + reviews[i].get_rating();
        }
    return float(sum_of_scores) / float(num_of_reviews);
}

void GoodReads::print_best_book_info()
{
    vector<float> all_scores;
    for (int i = 0; i < books.size(); ++i)
    {
        float rating = compute_book_score(books[i].get_id());
        all_scores.push_back(rating);
    }
    int max_index = max_element(all_scores.begin(), all_scores.end()) - all_scores.begin();
    books[max_index].print_book_info();
    for (int i = 0; i < authors.size(); ++i)
        if (authors[i].get_id() == books[max_index].get_author_id())
            cout << "Author: " << authors[i].get_name() << endl;
    cout << "Average Rating: " << fixed << setprecision(2) << all_scores[max_index] << endl;
}

int GoodReads::compute_reviwer_likes(int user_id)
{
    int user_likes = 0;
    for (int i = 0; i < reviews.size(); ++i)
        if (reviews[i].get_user_id() == user_id)
            user_likes += reviews[i].get_number_of_likes();
    return user_likes;
}


void GoodReads::print_best_reviewer_info()
{
    vector<int> all_users_likes;
    for (int i = 0; i < users.size(); ++i)
    {
        int user_likes = compute_reviwer_likes(users[i].get_id());
        all_users_likes.push_back(user_likes);
    }
    int max_index = max_element(all_users_likes.begin(), all_users_likes.end()) - all_users_likes.begin();
    users[max_index].print_user_info_one();
    vector<string> fave_authors = users[max_index].get_favorite_authors();
    sort(fave_authors.begin(), fave_authors.end());
    cout << "Favorite Authors: ";
    for (int i = 0; i < fave_authors.size(); ++i)
        for (int j = 0; j < authors.size(); ++j)
            if (authors[j].get_id() == stoi(fave_authors[i]))
            {
                if (i != fave_authors.size()-1)
                    cout <<  authors[j].get_name() << ", ";
                else
                    cout <<  authors[j].get_name();
            }
    cout << endl;
    users[max_index].print_user_info_two();
    cout << "Number of Likes: " << all_users_likes[max_index] << endl;   
}

int GoodReads::number_of_reviews_of_book(int book_id)
{
    int num_of_reviews_of_book = 0;
    for (int i = 0; i < reviews.size(); ++i)
        if(reviews[i].get_book_id() == book_id)
            num_of_reviews_of_book += 1;
    return num_of_reviews_of_book;
}

float GoodReads::compute_rating(int book_id)
{
    float rating = 0;
    for (int i = 0; i < reviews.size(); ++i)
        if (reviews[i].get_book_id() == book_id)
            rating += float(reviews[i].get_rating()) * compute_user_credit(reviews[i].get_user_id());
    int num_of_reviews_of_book = number_of_reviews_of_book(book_id);
    if (num_of_reviews_of_book != 0)
        return float(rating)/ float(num_of_reviews_of_book);
    else 
        return 0;
}

int GoodReads::compute_favorite_genres_score(int user_id, int book_id)
{
    string Favorite_genre;
    int score = 0;
    vector<string> user_fave_genres;
    for (int i = 0; i < users.size(); ++i)
        if (users[i].get_id() == user_id)
            user_fave_genres = users[i].get_favorite_genres();
    for (int i = 0; i < books.size(); ++i)
        if (books[i].get_id() == book_id)
            Favorite_genre = books[i].get_genre();
    for (int i = 0; i < user_fave_genres.size(); ++i)
        if (user_fave_genres[i] == Favorite_genre)
            score = 5;
    return score;
}

void GoodReads::print_best_book_for_user_info(int user_id)
{
    vector<float> all_books_scores;
    for (int i = 0; i < books.size(); ++i)
    {
        float score = compute_rating(books[i].get_id()) + float(compute_favorite_genres_score(user_id, books[i].get_id()));
        all_books_scores.push_back(score);
    }
    int max_index = max_element(all_books_scores.begin(), all_books_scores.end()) - all_books_scores.begin();
    books[max_index].print_book_info();  
    for (int i = 0; i < authors.size(); ++i)
        if (authors[i].get_id() == books[max_index].get_author_id())  
            cout << "Author: " << authors[i].get_name() << endl;
    cout << "Reviews: " << endl;
    for (int i = 0; i < reviews.size(); ++i)
        if (reviews[i].get_book_id() == books[max_index].get_id())
            cout << "id: " << reviews[i].get_id() << " Rating: " << reviews[i].get_rating() << " Likes: " << reviews[i].get_number_of_likes() << " Date: " << reviews[i].get_date() << endl;
}   

vector<int> GoodReads::find_close_followings_by_id(int user_id)
{
    vector<int> all_followings;
    vector<string> close_followings;
    for (int i = 0; i < follow_edges.size(); ++i)
        if (follow_edges[i].get_id() == user_id)
            close_followings = follow_edges[i].get_followings();
    for (int i = 0; i < close_followings.size(); ++i)
        all_followings.push_back(stoi(close_followings[i]));
    return all_followings;
}


bool GoodReads::check_if_in_list(vector<int> vec, int x)
{
    int cnt = 0;
    for (int i = 0; i < vec.size(); ++i )
        if (vec[i] != x)
            cnt += 1;
    if (cnt == vec.size())
        return 1;
    else
        return 0;
    
}

vector<int> GoodReads::find_all_followings(int user_id)
{
    vector<int> all_followings;
    vector<int> q;
    vector<int> neighbors;
    int current_user;
    q.push_back(user_id);
    while (q.size() > 0)
    {
        current_user = q[0];
        q.erase(q.begin());
        if (check_if_in_list(all_followings, current_user))
        {
            all_followings.push_back(current_user);
            neighbors = find_close_followings_by_id(current_user);
            for (int i = 0; i < neighbors.size(); ++i)
            {
                if (check_if_in_list(all_followings, neighbors[i]))
                    q.push_back(neighbors[i]);
            }
        } 
    }
    all_followings.erase(all_followings.begin());
    return all_followings;
}

vector<int> GoodReads::find_three_best_books_of_user(int user_id)
{
    vector<int> three_best_books;
    vector<float> all_books_scores;
    vector<string> read_books;
    for (int i = 0; i < users.size(); ++i)
        if (users[i].get_id() == user_id)
            read_books = users[i].get_read();

    for (int i = 0; i < read_books.size(); ++i)
    {
        float score = 0;
        score  = compute_rating(stoi(read_books[i]));
        all_books_scores.push_back(score);
    }

    if (read_books.size() > 3)
    {
        int max_index1 = max_element(all_books_scores.begin(), all_books_scores.end()) - all_books_scores.begin();
        float max1 = all_books_scores[max_index1];
        all_books_scores[max_index1] = 0;
        int max_index2 = max_element(all_books_scores.begin(), all_books_scores.end()) - all_books_scores.begin();
        float max2 = all_books_scores[max_index2];
        all_books_scores[max_index2] = 0;
        int max_index3 = max_element(all_books_scores.begin(), all_books_scores.end()) - all_books_scores.begin();
        float max3 = all_books_scores[max_index3];
        all_books_scores[max_index3] = 0;
        for (int i = 0; i < all_books_scores.size(); ++i)
        {
            if (all_books_scores[i] == max3 && stoi(read_books[i]) < stoi(read_books[max_index3]))
                max_index3 = i;
            if (all_books_scores[i] == max2 && stoi(read_books[i]) < stoi(read_books[max_index2]))
                max_index2 = i;
            if (all_books_scores[i] == max1 && stoi(read_books[i]) < stoi(read_books[max_index1]))
                max_index1 = i;
        }
        three_best_books.push_back(stoi(read_books[max_index1]));
        three_best_books.push_back(stoi(read_books[max_index2]));
        three_best_books.push_back(stoi(read_books[max_index3]));
    }
    else
        for (int i = 0; i < read_books.size(); ++i)
            three_best_books.push_back(stoi(read_books[i]));
    return three_best_books;
}

int GoodReads::find_most_repeated_element(vector<int> Vect)
{   
    sort(Vect.begin(), Vect.end());
    int Max = 0;
    int max_repeated_element = 0;
    for (int i = 0; i < Vect.size(); ++i)
        if (count(Vect.begin(), Vect.end(), Vect[i]) > Max)
        {
            Max = count(Vect.begin(), Vect.end(), Vect[i]);
            max_repeated_element = Vect[i];
        }
    return max_repeated_element;
}

int GoodReads::find_best_book_second_approach(int user_id)
{
    vector<int> all_followings = find_all_followings(user_id);
    vector<int> all_books;
    for (int i = 0; i < all_followings.size(); ++i)
        {
            vector<int> three_best_books = find_three_best_books_of_user(all_followings[i]);
            for (int j = 0; j < three_best_books.size(); ++j)
                all_books.push_back(three_best_books[j]);
        }
    int max_repeated_element = find_most_repeated_element(all_books);
    return max_repeated_element;
}

void GoodReads::print_best_book_info_second_approch(int book_id)
{
    books[book_id].print_book_info();  
    for (int i = 0; i < authors.size(); ++i)
        if (authors[i].get_id() == books[book_id].get_author_id())  
            cout << "Author: " << authors[i].get_name() << endl;
    cout << "Reviews: " << endl;
    for (int i = 0; i < reviews.size(); ++i)
        if (reviews[i].get_book_id() == books[book_id].get_id())
            cout << "id: " << reviews[i].get_id() << " Rating: " << reviews[i].get_rating() << " Likes: " << reviews[i].get_number_of_likes() << " Date: " << reviews[i].get_date() << endl;
}
