#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<Windows.h>

using namespace std;

class users;
class pages;
class posts;
void driver();
void start_neon();
void read();

class users
{
private:
	string user_name;
	int user_id;
	string friends_name[10];
	int friends_id[10];

public:
	users();
	void set_current_user(users* currentUserPtr);
	void intialize_users(users* usersPtr);
	void display_users(users* usersPtr, int& size, int& i);
	void timeline(users* currentUserPtr);
	void friends_list(users* currentUserPtr);
	void search_users(users* usersPtr, int& size);
	~users();
};

class pages : public users
{
private:
	string pages_title;
	int pages_id;

public:
	pages();
	void intialize_pages(pages* pagesPtr);
	void display_pages(pages* pagesPtr, int& size, int& i);
	void view_page(pages* pagesPtr, int& size, users* usersPtr, posts* postsPtr);
	void search_pages(pages* pagesPtr, int& size);
	~pages();
};

class posts : public pages
{
private:
	int post_id;
	string post_description;
	int post_likes;
	string post_comments[10];
	tm* post_shared_date;
	int day, month, year;
	int p_ids = 5000; /*a variable is used for initializing the posts IDs from 1-15*/

public:
	posts();
	void intialize_posts(posts* postsPtr);
	void display_posts(posts* postsPtr, int& size, int& i, users* usersPtr);
	void like_post(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr);
	void view_post(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr);
	void comment_post(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr);
	void delete_comment(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr);
	void timeline_posts(posts* postsPtr, int& size, int& i);
	void create_post(posts* postsPtr);
	void share_post(posts* postsPtr);
	void search_posts(posts* postsPtr, int& size, pages* pagesPtr, users* usersPtr);
	~posts();
};
