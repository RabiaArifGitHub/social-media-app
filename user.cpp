#include"user.h"
//creates and opens this text file
ofstream mydata("SocialNetworkData.txt");
ifstream read_data("SocialNetworkData.txt");
void driver()
{
	//objects and pointers
	users usersObj;
	posts postsObj;
	pages pagesObj;
	int sizeOfUsersPtr = 7;
	int sizeOfPostsPtr = 20;
	int sizeOfPagesPtr = 5;
	users* currentUserPtr;
	users* usersPtr;
	posts* postsPtr;
	pages* pagesPtr;
	currentUserPtr = new users[1];
	usersPtr = new users[sizeOfUsersPtr];
	postsPtr = new posts[sizeOfPostsPtr];
	pagesPtr = new pages[sizeOfPagesPtr];
	try
	{
		//set user and initialize
		usersObj.set_current_user(currentUserPtr);
		usersObj.intialize_users(usersPtr);
		postsObj.intialize_posts(postsPtr);
		pagesObj.intialize_pages(pagesPtr);

		start_neon();
		//displaying homepage
		cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - HOMEPAGE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		for (int i = 0; i < (sizeOfUsersPtr); i++) {
			usersObj.display_users(usersPtr, sizeOfUsersPtr, i);
			postsObj.display_posts(postsPtr, sizeOfPostsPtr, i, usersPtr);
			cout << endl << endl;
		}
		for (int i = 0, j = 10; i < (5); i++, j++)
		{
			pagesObj.display_pages(pagesPtr, sizeOfPagesPtr, i);
			postsObj.display_posts(postsPtr, sizeOfPostsPtr, j, usersPtr);
			cout << endl << endl;
		}

		//menu
		int command;
		do
		{
			cout << "========================================================================================================================================================================\n";
			cout << "\t\t\t\t\t\t\t\tEnter 0 to Exit the program"
				<< "\n\t\t\t\t\t\t\t\tEnter 1 to Like a Post"
				<< "\n\t\t\t\t\t\t\t\tEnter 2 to View a Post"
				<< "\n\t\t\t\t\t\t\t\tEnter 3 to Comment on a Post"
				<< "\n\t\t\t\t\t\t\t\tEnter 4 to Delete your Comment on a Post"
				<< "\n\t\t\t\t\t\t\t\tEnter 5 to Create a Post"
				<< "\n\t\t\t\t\t\t\t\tEnter 6 to Share a Post"
				<< "\n\t\t\t\t\t\t\t\tEnter 7 to View a Page"
				<< "\n\t\t\t\t\t\t\t\tEnter 8 to View Timeline"
				<< "\n\t\t\t\t\t\t\t\tEnter 9 to View Friends List"
				<< "\n\t\t\t\t\t\t\t\tEnter 10 to Search"
				<< "\n\t\t\t\t\t\t\t\tEnter 11 to View Homepage"
				<< "\n\t\t\t\t\t\t\t\tEnter 12 to Read data from SocialNetworkData.txt"
				<< "\n\n\t\t\t\t\t\t\t\tCOMMAND...	";

			while (1)
			{
				try {
					while (!(cin >> command))
					{
						cout << "\n\t\t\t\t\t\t\t\tCOMMAND...	";
						cin.clear();
						cin.ignore();
						throw "Invalid Input!";
					}
					break;
				}
				catch (const char y[]) //Exception Handeled
				{
					cout << y << endl;
					cout << "\n\t\t\t\t\t\t\t\tCOMMAND...	";
				}
			}
			cout << "========================================================================================================================================================================\n";
			switch (command) {
			case 0: {
				cout << "\n\t\t\t\t\t\t\t\t[NEON application exited successfully]\n";
				cout << "\n\t\t\t\t\t\t[----------  Usman Bashir\tRabia Arif\tMuhammad Usman  ----------]\n";
				break;
			}
			case 1: {
				start_neon();
				postsObj.like_post(postsPtr, sizeOfPostsPtr, usersPtr, pagesPtr);
				break;
			}
			case 2: {
				start_neon();
				postsObj.view_post(postsPtr, sizeOfPostsPtr, usersPtr, pagesPtr);
				break;
			}

			case 3: {
				start_neon();
				postsObj.comment_post(postsPtr, sizeOfPostsPtr, usersPtr, pagesPtr);
				break;
			}
			case 4: {
				start_neon();
				postsObj.delete_comment(postsPtr, sizeOfPostsPtr, usersPtr, pagesPtr);
				break;
			}
			case 5: {
				start_neon();
				postsObj.create_post(postsPtr);
				break;
			}
			case 6:
			{
				start_neon();
				postsObj.share_post(postsPtr);
				break;
			}
			case 7: {
				start_neon();
				pagesObj.view_page(pagesPtr, sizeOfPagesPtr, usersPtr, postsPtr);
				break;
			}
			case 8: {
				start_neon();
				int i = 0, user_size = sizeOfPostsPtr - 10;
				usersObj.timeline(currentUserPtr); //for printing current user's name
				postsObj.timeline_posts(postsPtr, user_size, i);
				break;
			}
			case 9: {
				start_neon();
				usersObj.friends_list(currentUserPtr);
				break;
			}
			case 10: {
				start_neon();
				int search;
				bool check = FALSE;
				cout << "Do you want to search in (1) users? (2) pages? (3) posts? Or enter 0 to exit search.\nEnter:\t";
				while (1)
				{
					try
					{
						while (!(cin >> search)) //Exception Handeled (type check)
							throw "Invalid Input! Enter again: ";
						break;
					}
					catch (const char x[])
					{
						cout << x << endl;
					}
					cin >> search;

					if (search >= 0 && search <= 3)
						check = TRUE;
					else
						cout << "Invalid Input! Enter again: ";
				}
				if (search == 0)
					break;
				else if (search == 1)
					usersObj.search_users(usersPtr, sizeOfUsersPtr);
				else if (search == 2)
					pagesObj.search_pages(pagesPtr, sizeOfPagesPtr);
				else if (search == 3)
					postsObj.search_posts(postsPtr, sizeOfPostsPtr, pagesPtr, usersPtr);
				break;
			}
			case 11: {
				start_neon();
				cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - HOMEPAGE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
				for (int i = 0; i < (sizeOfUsersPtr); i++) {
					usersObj.display_users(usersPtr, sizeOfUsersPtr, i);
					postsObj.display_posts(postsPtr, sizeOfPostsPtr, i, usersPtr);
					cout << endl << endl;
				}
				for (int i = 0, j = 10; i < (5); i++, j++)
				{
					pagesObj.display_pages(pagesPtr, sizeOfPagesPtr, i);
					postsObj.display_posts(postsPtr, sizeOfPostsPtr, j, usersPtr);
					cout << endl << endl;
				}
				break;
			}
			case 12: {
				start_neon();
				read();
				break;
			}
			default:
			{
				start_neon();
				cout << "\t\t\t\tEnter a valid command please!";
				cout << endl;
				break;
			}
			}
		} while (command != 0);
	}
	catch (const char x[])
	{
		cout << x << endl;
	}
	cout << endl;

	//deallocating memory
	delete[] currentUserPtr;
	currentUserPtr = nullptr;
	delete[] usersPtr;
	usersPtr = nullptr;
	delete[] postsPtr;
	postsPtr = nullptr;
	delete[] pagesPtr;
	pagesPtr = nullptr;
}
void start_neon()
{
	system("cls");
	cout << "========================================================================================================================================================================\n";
	cout << "                                                                        N    E    O    N\n";
	cout << "========================================================================================================================================================================\n";
	cout << endl;
}
void read()
{
	if (!mydata.is_open() || !read_data.is_open())
		throw "Can't open SocialNetworkData.txt";
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - SocialNetworkData.txt - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	string str;
	while (getline(read_data, str))
		cout << str << endl;
	mydata.close();
	read_data.close();
}
// users class //////////////////////////////////////////////////////////////////////////////////////////////////////
users::users()
{
	user_name = " ";
	user_id = 0;
	for (int i = 0; i < 10; i++)
	{
		friends_name[i] = " ";
		friends_id[i] = 0;
	}
}
void users::set_current_user(users* currentUserPtr)
{
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - SETTING YOUR PROFILE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	cout << "Enter your ID (a 4-digit number): ";
	while (1)
	{
		try {

			while (!(cin >> currentUserPtr[0].user_id) || currentUserPtr[0].user_id < 1000 || currentUserPtr[0].user_id>9999)
			{
				cin.clear();
				cin.ignore();
				throw "Invalid Input!";
			}
			break;
		}
		catch (const char y[]) //Exception Handeled
		{
			cout << y << endl;
		}
	}
	cout << "Enter your NAME: ";
	cin.ignore();
	getline(cin, currentUserPtr[0].user_name);
	mydata << "<user>" << "<" << currentUserPtr[0].user_id << ">" << "<" << currentUserPtr[0].user_name << ">" << endl;
	time_t t = time(0);	//time function gives system time in seconds elapsed 1 Jan 1970
	tm* tPtr = localtime(&t);	//localtime function sets that time according to current local time
	//the following keywords pointing to tPtr are built-in and convert the time in proper format
	cout << "\nSystem Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "System Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec) << endl;
	cout << "[Current user set successfully!]";
	//intialize current user's friends names
	/*I am intializing only 5 friends out of 10 for current user*/
	//intialize current user's friends names
	currentUserPtr[0].friends_name[0] = "Shahid Ahmad";
	currentUserPtr[0].friends_name[1] = "Sean Michael";
	currentUserPtr[0].friends_name[2] = "Kinza Khan";
	currentUserPtr[0].friends_name[3] = "John Andrews";
	currentUserPtr[0].friends_name[4] = "Ali Bilal";
	//intialize current user's friends ids
	currentUserPtr[0].friends_id[0] = 2011;
	currentUserPtr[0].friends_id[1] = 9190;
	currentUserPtr[0].friends_id[2] = 1221;
	currentUserPtr[0].friends_id[3] = 4243;
	currentUserPtr[0].friends_id[4] = 2123;
	mydata << "-------List of Friends-------" << endl;
	for (int i = 0; i < 5; i++)
		mydata << "<friend>\t" << currentUserPtr[0].friends_id[i] << "\t" << currentUserPtr[0].friends_name[i] << endl;
	Sleep(1500);
}
void users::intialize_users(users* usersPtr)
{
	//initialize names
	usersPtr[0].user_name = "Raaviya Ali";
	usersPtr[1].user_name = "Parveen Junaid";
	usersPtr[2].user_name = "Alia Naseem";
	usersPtr[3].user_name = "Fahad Malik";
	usersPtr[4].user_name = "Imaan Shakeel";
	usersPtr[5].user_name = "Kiran Habib";
	usersPtr[6].user_name = "Sultan Shah";
	//initialize ids with unique 4 digits
	usersPtr[0].user_id = 1012;
	usersPtr[1].user_id = 3131;
	usersPtr[2].user_id = 4442;
	usersPtr[3].user_id = 9192;
	usersPtr[4].user_id = 7119;
	usersPtr[5].user_id = 4100;
	usersPtr[6].user_id = 6546;
	/*I am intializing only 3, 3 friends out of 10 for every user*/
	//intialize friends names
	//0
	usersPtr[0].friends_name[0] = "Alex";
	usersPtr[0].friends_name[1] = "Mike";
	usersPtr[0].friends_name[2] = "Hameed";
	//1
	usersPtr[1].friends_name[0] = "Gerald";
	usersPtr[1].friends_name[1] = "Shiva";
	usersPtr[1].friends_name[2] = "Khan";
	//2
	usersPtr[2].friends_name[0] = "Leena";
	usersPtr[2].friends_name[1] = "Reina";
	usersPtr[2].friends_name[2] = "Momina";
	//3
	usersPtr[3].friends_name[0] = "Yuneeb";
	usersPtr[3].friends_name[1] = "Emaaz";
	usersPtr[3].friends_name[2] = "Maaz";
	//4
	usersPtr[4].friends_name[0] = "Pico";
	usersPtr[4].friends_name[1] = "Lima";
	usersPtr[4].friends_name[2] = "Oxy";
	//5
	usersPtr[5].friends_name[0] = "Jaaved";
	usersPtr[5].friends_name[1] = "Saad";
	usersPtr[5].friends_name[2] = "Osmaan";
	//6
	usersPtr[6].friends_name[0] = "James";
	usersPtr[6].friends_name[1] = "Harold";
	usersPtr[6].friends_name[2] = "Posty";
	//intialize friends ids
	int f_ids = 1000; /*a variable is used for initializing the friends list for each user from 1-7*/
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			usersPtr[i].friends_id[j] = f_ids;
			f_ids++;
		}
	}
}
void users::display_users(users* usersPtr, int& size, int& i)
{

	cout << "......................................................\n";
	cout << usersPtr[i].user_name << " (" << usersPtr[i].user_id << ") " << "shared a post with Post-ID ";
}
void users::timeline(users* currentUserPtr)
{
	cout << "\n\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << currentUserPtr[0].user_name << "'s TIMELINE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";
}
void users::friends_list(users* currentUserPtr)
{
	cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << currentUserPtr[0].user_name << "'s FRIENDS LIST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	cout << left << setw(20) << "NAMES" << "USER IDS\n\n";
	for (int i = 0; i < 10; i++)
	{
		if (currentUserPtr[0].friends_id[i] == 0)
			break;
		cout << left << setw(20) << currentUserPtr[0].friends_name[i];
		cout << "[" << currentUserPtr[0].friends_id[i] << "]" << endl;
	}
	cout << endl;
}


void users::search_users(users* usersPtr, int& size)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - SEARCH A USER - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	string search_key;
	int temp = 0;
	size_t searched = -1, pos = 0, length = 0;
	//user enters search
	cout << "\nEnter search key: ";
	while (1)
	{
		try {
			while (!(cin >> search_key))
			{
				cout << "\nEnter search key: ";
				cin.clear();
				cin.ignore();
				throw "Invalid Input!";
			}
			break;
		}
		catch (const char y[]) //Exception Handeled
		{
			cout << y << endl;
			cout << "\nEnter search key: ";
		}
	}
	//it is searched in users array
	for (int j = 0; j < size; j++)
	{
		searched = usersPtr[j].user_name.find(search_key);
		if (searched != string::npos) {
			temp = 1;
			pos = j;
			break;
		}
	}
	if (temp == 0)
		cout << "\nNo such usernames found!\n";
	else
	{
		cout << "\nSearch found in usernames...\n";
		cout << "Username is " << usersPtr[pos].user_name << " with ID " << usersPtr[pos].user_id << endl;
	}
}
users::~users()
{

}

// posts class ///////////////////////////////////////////////////////////////////////////////////////////////////////
posts::posts()
{
	post_id = 0;
	post_description = "";
	post_likes = 0;
	for (int i = 0; i < 10; i++)
		post_comments[i] = "";
	time_t t = time(0);
	post_shared_date = localtime(&t);
	day = 0;
	month = 0;
	year = 0;
}
void posts::share_post(posts* postsPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - SHARE A POST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	if (postsPtr[9].post_description != "")
		throw "USER CAN ONLY SHARE 10 POSTS AT MAX!";
	int searchid;
	bool found = false;
	cout << "Enter post id: ";
	cin >> searchid;
	for (int i = 10; i < 20; i++)
	{
		if (postsPtr[i].post_id == searchid)
		{
			for (int j = 0; j < 10; j++) //for copying post to timeline
			{
				if (postsPtr[j].post_description == "")
				{
					postsPtr[j].post_id = postsPtr[i].post_id;
					postsPtr[j].post_description = postsPtr[i].post_description;
					postsPtr[j].post_likes = postsPtr[i].post_likes;
					time_t t = time(0);
					post_shared_date = localtime(&t);
					postsPtr[j].day = post_shared_date->tm_mday;
					postsPtr[j].month = post_shared_date->tm_mon;
					postsPtr[j].year = post_shared_date->tm_year + 1900;
					//a counter for counting comments number
					int counter = 0;
					for (int k = 0; k < 10; k++)
					{
						if (!(postsPtr[i].post_comments[k].empty()))
							counter++;
					}
					for (int l = 0; l < counter; l++)
						postsPtr[j].post_comments[l] = postsPtr[i].post_comments[l];
					found = true;
					cout << "POST SHARED ON YOUR TIMELINE SUCCESSFULLY!" << endl;
					break;
				}
			}
		}
	}
	if (found == false)
		cout << "POST NOT FOUND" << endl;
}
void posts::create_post(posts* postsPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - CREATE A NEW POST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	if (postsPtr[9].post_description != "")
		throw "USER CAN ONLY SHARE 10 POSTS AT MAX!";
	cout << "Share on your timeline..." << endl;
	static int p = 5006;
	for (int i = 7; i < 10; i++)
	{
		if (postsPtr[i].post_description == "")
		{
			p++;
			postsPtr[i].post_id = p;
			cin.ignore();
			getline(cin, postsPtr[i].post_description);
			time_t t = time(0);
			post_shared_date = localtime(&t);
			postsPtr[i].day = post_shared_date->tm_mday;
			postsPtr[i].month = post_shared_date->tm_mon;
			postsPtr[i].year = post_shared_date->tm_year + 1900;
			cout << "Uploading your post..." << endl;
			Sleep(3000);
			cout << "\aPOSTED!" << endl;
			break;
		}
	}
}
void posts::search_posts(posts* postsPtr, int& size, pages* pagesPtr, users* usersPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - SEARCHING A POST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	size_t searched = -1;
	string search_key;
	int temp = 0, pos = 0, pages_pos = 0;
	int sizeOfUsersPtr = 8, sizeOfPagesPtr = 5;
	//user enters search
	cout << "\nEnter search key: ";
	while (1)
	{

		try {
			while (!(cin >> search_key))
			{
				cout << "\nEnter search key: ";
				cin.clear();
				cin.ignore();
				throw "Invalid Input!";
			}
			break;
		}
		catch (const char y[]) //Exception Handeled
		{
			cout << y << endl;
			cout << "\nEnter search key: ";
		}
	}
	//it is searched in posts array
	for (int j = 0; j < size; j++)
	{
		searched = (postsPtr[j].post_description.find(search_key));
		if (searched != string::npos)
		{
			temp = 1;
			pos = j;
			break;
		}
	}
	//display
	if (temp == 0)
		cout << "\nNo such posts found!\n";
	else
	{
		cout << "\nSearch found in posts...\n";
		if (pos > 9 && pos <= 19) {
			if (pos == 10)
				pages_pos = 0;
			else if (pos == 11)
				pages_pos = 1;
			else if (pos == 12)
				pages_pos = 2;
			else if (pos == 13)
				pages_pos = 3;
			else if (pos == 14)
				pages_pos = 4;
			pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
		}
		else if (pos <= 9) {
			usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
		}
		postsPtr->display_posts(postsPtr, size, pos, usersPtr);
	}
}
void posts::intialize_posts(posts* postsPtr)
{
	//intialize posts ids
	for (int i = 0; i < 20; i++)
	{
		postsPtr[i].post_id = p_ids;
		p_ids++;
	}
	//initialize post description
	//posts index 0 to 9 are users posts
	//User has 7 posts on his timeline already
	//he can share 3 more posts
	postsPtr[0].post_description = "Not your speed so catch up or get left behind.";
	postsPtr[1].post_description = "You gotta walk it like you talk it";
	postsPtr[2].post_description = "Guys! Pray for me. My result is about to be announced soon!";
	postsPtr[3].post_description = "Feeling sad with 11 others :(";
	postsPtr[4].post_description = "Imagine how stupid one would have to be to support the flat-earth theory LOL\nI can be stupid but never stupid enough to support the fLaT EaRtH tHeOrY!!";
	postsPtr[5].post_description = "Turned 25 today";
	postsPtr[6].post_description = "I feel hangry (angry + hungry)!!! Can someone get me pasta? Hehe :p";
	//posts index 10 to 20 are community/pages posts
	postsPtr[10].post_description = "Spring 2021 admissions are now opened! Get admission now.";
	postsPtr[11].post_description = "Head to our YouTube channel to watch: How to make tasty chicken shawarmas.";
	postsPtr[12].post_description = "The most watched movie has been Enola Holmes this week in Pakistan.";
	postsPtr[13].post_description = "PAK v IND match updates: Pakistani Batsman Shahid Afridi scored a century after eons!";
	postsPtr[14].post_description = "SpaceX satellites have been successfully able to capture a distant rogue planet.";
	//initialize post shared date
	time_t t = time(0);
	post_shared_date = localtime(&t);
	//0
	postsPtr[0].day = postsPtr[0].post_shared_date->tm_mday - 1;
	postsPtr[0].month = postsPtr[0].post_shared_date->tm_mon + 1;
	postsPtr[0].year = postsPtr[0].post_shared_date->tm_year + 1900;
	//1
	postsPtr[1].day = postsPtr[1].post_shared_date->tm_mday;
	postsPtr[1].month = postsPtr[1].post_shared_date->tm_mon + 1;
	postsPtr[1].year = postsPtr[1].post_shared_date->tm_year + 1900;
	//2
	postsPtr[2].day = postsPtr[2].post_shared_date->tm_mday - 2;
	postsPtr[2].month = postsPtr[2].post_shared_date->tm_mon + 1;
	postsPtr[2].year = postsPtr[2].post_shared_date->tm_year + 1900;
	//3
	postsPtr[3].day = postsPtr[3].post_shared_date->tm_mday - 3;
	postsPtr[3].month = postsPtr[3].post_shared_date->tm_mon + 1;
	postsPtr[3].year = postsPtr[3].post_shared_date->tm_year + 1900;
	//4
	postsPtr[4].day = postsPtr[4].post_shared_date->tm_mday - 1;
	postsPtr[4].month = postsPtr[4].post_shared_date->tm_mon + 1;
	postsPtr[4].year = postsPtr[4].post_shared_date->tm_year + 1900;
	//5
	postsPtr[5].day = postsPtr[5].post_shared_date->tm_mday;
	postsPtr[5].month = postsPtr[5].post_shared_date->tm_mon + 1;
	postsPtr[5].year = postsPtr[5].post_shared_date->tm_year + 1900;
	//6
	postsPtr[6].day = postsPtr[6].post_shared_date->tm_mday - 2;
	postsPtr[6].month = postsPtr[6].post_shared_date->tm_mon + 1;
	postsPtr[6].year = postsPtr[6].post_shared_date->tm_year + 1900;
	//10
	postsPtr[10].day = postsPtr[10].post_shared_date->tm_mday - 1;
	postsPtr[10].month = postsPtr[10].post_shared_date->tm_mon + 1;
	postsPtr[10].year = postsPtr[10].post_shared_date->tm_year + 1900;
	//11
	postsPtr[11].day = postsPtr[11].post_shared_date->tm_mday - 4;
	postsPtr[11].month = postsPtr[11].post_shared_date->tm_mon + 1;
	postsPtr[11].year = postsPtr[11].post_shared_date->tm_year + 1900;
	//12
	postsPtr[12].day = postsPtr[12].post_shared_date->tm_mday - 3;
	postsPtr[12].month = postsPtr[12].post_shared_date->tm_mon + 1;
	postsPtr[12].year = postsPtr[12].post_shared_date->tm_year + 1900;
	//13
	postsPtr[13].day = postsPtr[13].post_shared_date->tm_mday - 1;
	postsPtr[13].month = postsPtr[13].post_shared_date->tm_mon + 1;
	postsPtr[13].year = postsPtr[13].post_shared_date->tm_year + 1900;
	//14
	postsPtr[14].day = postsPtr[14].post_shared_date->tm_mday - 2;
	postsPtr[14].month = postsPtr[14].post_shared_date->tm_mon + 1;
	postsPtr[14].year = postsPtr[14].post_shared_date->tm_year + 1900;
	//initialize post likes
	srand((unsigned int)time(NULL));
	int p_likes; /*a variable is used for randomly initializing the posts likes*/
	for (int i = 0; i < 20; i++)
	{
		if (i < 7 || i>9) {
			p_likes = (rand() % 10 + 1);
			postsPtr[i].post_likes = p_likes;
			p_likes++;
		}
	}
	//initialize post comments
	//0
	postsPtr[0].post_comments[0] = "Hahahaha";
	postsPtr[0].post_comments[1] = "So savage!";
	postsPtr[0].post_comments[2] = "Woah. Ok!!";
	//1
	postsPtr[1].post_comments[0] = "Yes";
	postsPtr[1].post_comments[1] = "Louder!";
	postsPtr[1].post_comments[2] = "Walk that talk yesss";
	postsPtr[1].post_comments[3] = "Queen <3";
	//2
	postsPtr[2].post_comments[0] = "Omg";
	postsPtr[2].post_comments[1] = "Wish you all the best buddy!";
	postsPtr[2].post_comments[2] = "You are going to rock it!";
	postsPtr[2].post_comments[3] = "Haha I can understand";
	postsPtr[2].post_comments[4] = "May Allah give you the best score Ameen";
	postsPtr[2].post_comments[5] = "We're praying, don't worry man";
	//3
	postsPtr[3].post_comments[0] = "Awww why";
	postsPtr[3].post_comments[1] = "Omg what";
	postsPtr[3].post_comments[2] = "Why?!";
	//4
	postsPtr[4].post_comments[0] = "Damn";
	postsPtr[4].post_comments[1] = "I cannot believe such theories still exist!";
	//5
	postsPtr[5].post_comments[0] = "Hey HBD!!!";
	postsPtr[5].post_comments[1] = "Happy Birthday! May you have many more.";
	postsPtr[5].post_comments[2] = "Happy Birthday love!!!";
	postsPtr[5].post_comments[3] = "Welcome to the mid-twenties buddy. HBD!";
	postsPtr[5].post_comments[4] = "Happy Birthday";
	postsPtr[5].post_comments[5] = "Happy birthdayyy";
	postsPtr[5].post_comments[6] = "May you be blessed with a wonderful life! Happy Birthday";
	//6
	postsPtr[6].post_comments[0] = "LOL";
	postsPtr[6].post_comments[1] = "Send your location, buddy, I will buy you :D";
	postsPtr[6].post_comments[2] = "Haha okayyy";
	//10
	postsPtr[10].post_comments[0] = "Kids, don't get admission here XD";
	//11
	postsPtr[11].post_comments[0] = "Yummy!";
	postsPtr[11].post_comments[1] = "Best <3";
	//12
	postsPtr[12].post_comments[0] = "Henry Cavill looks so great in this movie!";
	//13
	postsPtr[13].post_comments[0] = "WHATTT!!!";
	postsPtr[13].post_comments[1] = "Unbelievable";
	postsPtr[13].post_comments[2] = "This is crazy!";
	postsPtr[13].post_comments[3] = "I don't believe this LOL";
	postsPtr[13].post_comments[4] = "Congrats Lala";
	//14
	postsPtr[14].post_comments[0] = "Wow";
	postsPtr[14].post_comments[1] = "What about SpaceX and NASA collab!?";
}
void posts::timeline_posts(posts* postsPtr, int& size, int& i)
{
	for (i = 0; i < size; i++)
	{
		if (postsPtr[i].post_description != "")
		{
			cout << postsPtr[i].post_id << ":\n";
			cout << postsPtr[i].post_description << "\n";
			cout << "[" << postsPtr[i].post_likes << " Likes]\n";
			cout << "Shared on " << postsPtr[i].day << "/" << postsPtr[i].month << "/" << postsPtr[i].year << endl;
			//a counter for counting comments number
			int counter = 0;
			for (int j = 0; j < 10; j++)
			{
				if (!(postsPtr[i].post_comments[j].empty()))
					counter++;
			}
			cout << counter << " Comments:\n";
			for (int j = 0; j < counter; j++)
				cout << "> " << postsPtr[i].post_comments[j] << "\n";
		}
	}
}
void posts::display_posts(posts* postsPtr, int& size, int& i, users* usersPtr)
{
	if (postsPtr[i].post_description != "")
	{
		cout << postsPtr[i].post_id << ":\n";
		cout << postsPtr[i].post_description << "\n";
		cout << "[" << postsPtr[i].post_likes << " Likes]\n";
		cout << "Shared on " << postsPtr[i].day << "/" << postsPtr[i].month << "/" << postsPtr[i].year << endl;
		//a counter for counting comments number
		int counter = 0;
		for (int j = 0; j < 10; j++)
		{
			if (!(postsPtr[i].post_comments[j].empty()))
				counter++;
		}
		cout << counter << " Comments:\n";
		for (int j = 0; j < counter; j++)
			cout << "> " << postsPtr[i].post_comments[j] << "\n";
	}
}
void posts::like_post(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - LIKE A POST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	int temp = 0, pos = 0, post_id_like, pages_pos = 0;
	int sizeOfUsersPtr = 8, sizeOfPagesPtr = 5;
	//user enters ID
	cout << "\nEnter post ID to like it: ";
	while (1)
	{
		try {
			while (!(cin >> post_id_like)) //Exception Handeled
			{
				cout << "Invalid ID!...\n" << "Enter post ID to like it: ";
				cin.clear();
				cin.ignore();
				throw "Invalid ID!";
			}
			break;
		}
		catch (const char y[])
		{
			cout << y << endl;
			cout << "Invalid ID!...\n" << "Enter post ID to like it: ";
		}
	}

	//ID is searched
	for (int j = 0; j < size; j++)
	{
		if (post_id_like == postsPtr[j].post_id)
		{
			temp = 1;
			pos = j;
			break;
		}
		
	}
	//display
	if (temp == 0) {
		cout << "Invalid post-ID!\n";
	}
	else {
		if (postsPtr[pos].post_likes < 10)
		{
			postsPtr[pos].post_likes++;
			cout << "\nThe post with ID " << post_id_like << " is: \n";
			if (pos > 9 && pos <= 19) {
				if (pos == 10)
					pages_pos = 0;
				else if (pos == 11)
					pages_pos = 1;
				else if (pos == 12)
					pages_pos = 2;
				else if (pos == 13)
					pages_pos = 3;
				else if (pos == 14)
					pages_pos = 4;
				pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
			}
			else if (post_id_like >= 5007)
			{
				postsPtr[pos].post_likes++;
				postsPtr[pos].post_likes--;
				//break;
			}
			else if (pos <= 9) {
				usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
			}
			postsPtr->display_posts(postsPtr, size, pos, usersPtr);
		}
		else
		{
			cout << "\nSorry, post likes are 10. A post cannot be liked by more than 10 users.\n";
			cout << "\nThe post with ID " << post_id_like << " is: \n";
			if (pos > 9 && pos <= 19) {
				if (pos == 10)
					pages_pos = 0;
				else if (pos == 11)
					pages_pos = 1;
				else if (pos == 12)
					pages_pos = 2;
				else if (pos == 13)
					pages_pos = 3;
				else if (pos == 14)
					pages_pos = 4;
				pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
			}
			else if (pos <= 9) {
				usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
			}
			postsPtr->display_posts(postsPtr, size, pos, usersPtr);
		}
	}
	cout << endl;
}
void posts::view_post(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - VIEW A POST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	int temp = 0, pos = 0, post_id_view, pages_pos = 0;
	int sizeOfUsersPtr = 8, sizeOfPagesPtr = 5;
	//user enters ID
	cout << "\nEnter post ID to view it: ";


	while (1)
	{
		try {
			while (!(cin >> post_id_view))//Exception Handeled
			{
				cout << "Invalid ID!...\n" << "Enter post ID to view it: ";
				cin.clear();
				cin.ignore();
				throw "Invalid ID!";
			}
			break;
		}
		catch (const char y[])
		{
			cout << y << endl;
			cout << "Invalid ID!...\n" << "Enter post ID to view it: ";
		}
	}
	//ID is searched
	for (int j = 0; j < size; j++)
	{
		if (post_id_view == postsPtr[j].post_id)
		{
			temp = 1;
			pos = j;
			break;
		}
	}
	//display
	if (temp == 0) {
		cout << "Invalid post-ID!\n";
	}
	else {
		if (pos > 9 && pos <= 19) {
			if (pos == 10)
				pages_pos = 0;
			else if (pos == 11)
				pages_pos = 1;
			else if (pos == 12)
				pages_pos = 2;
			else if (pos == 13)
				pages_pos = 3;
			else if (pos == 14)
				pages_pos = 4;
			pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
		}
		else if (pos <= 9) {
			usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
		}
		postsPtr->display_posts(postsPtr, size, pos, usersPtr);
	}
	cout << endl;
}
void posts::comment_post(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - COMMENT ON A POST - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	string users_comment;
	int temp = 0, temp2 = 0, pos = 0, post_id_comment, pages_pos = 0, comment_not_empty = 0;
	int sizeOfUsersPtr = 8, sizeOfPagesPtr = 5;
	//user enters ID
	cout << "\nEnter post ID to comment on it: ";
	while (1)
	{
		try
		{
			while (!(cin >> post_id_comment))//Exception Handeled
			{
				cout << "Invalid ID!...\n" << "Enter post ID to comment on it: ";
				cin.clear();
				cin.ignore(100, '\n');
			}
			break;
		}
		catch (const char y[])
		{
			cout << y << endl;
			cout << "Invalid ID!...\n" << "Enter post ID to comment on it: ";
		}
	}
//ID is searched
for (int j = 0; j < size; j++)
{
	if (post_id_comment == postsPtr[j].post_id)
	{
		temp = 1;
		pos = j;
		break;
	}
}
//display
if (temp == 0) {
	cout << "Invalid post-ID!\n";
}
else {
	//post is shown first
	cout << "\nThe post with ID " << post_id_comment << " is: \n";
	if (pos > 9 && pos <= 19) {
		if (pos == 10)
			pages_pos = 0;
		else if (pos == 11)
			pages_pos = 1;
		else if (pos == 12)
			pages_pos = 2;
		else if (pos == 13)
			pages_pos = 3;
		else if (pos == 14)
			pages_pos = 4;
		pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
	}
	else if (pos <= 9) {
		usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
	}
	postsPtr->display_posts(postsPtr, size, pos, usersPtr);
	//user enters comment
	bool strcheck = true;
	int strcheck1 = 0;
	while (strcheck == true)//Exception Handeled
	{
		cout << "\nEnter your comment to be posted: ";
		cin.ignore();
		getline(cin, users_comment);
		stringstream ss(users_comment);
		if (ss >> strcheck1)
		{
			cout << "Input Error, The Comment cannot start with a numeric digit" << endl;
			strcheck = true;
		}
		else
			strcheck = false;
	}
	strcheck = true;
	strcheck1 = 0;
	//updated post with user's comment is shown
	string add_usersname, updated_user_comment;
	add_usersname = " [your comment]";
	users_comment = users_comment + add_usersname;
	for (int j = 0; j < 10; j++)
	{
		if (postsPtr[pos].post_comments[j].empty()) {
			comment_not_empty = j;
			postsPtr[pos].post_comments[comment_not_empty] = users_comment;
			break;
		}
	}
	if (pos > 9 && pos <= 19) {
		if (pos == 10)
			pages_pos = 0;
		else if (pos == 11)
			pages_pos = 1;
		else if (pos == 12)
			pages_pos = 2;
		else if (pos == 13)
			pages_pos = 3;
		else if (pos == 14)
			pages_pos = 4;
		pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
	}
	else if (pos <= 9) {
		usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
	}
	postsPtr->display_posts(postsPtr, size, pos, usersPtr);
}
cout << endl;
}
void posts::delete_comment(posts* postsPtr, int& size, users* usersPtr, pages* pagesPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - DELETE YOUR COMMENT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	int temp = 0, pos = 0, post_id_comment, pages_pos = 0, comment_not_empty = 0;
	int sizeOfUsersPtr = 8, sizeOfPagesPtr = 5;
	//user enters ID
	cout << "\nEnter post ID to delete a comment on it: ";
	while (!(cin >> post_id_comment))	//Exception Handeled
	{
		cout << "Invalid ID!...\n" << "Enter post ID to comment on it: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	//ID is searched
	for (int j = 0; j < size; j++)
	{
		if (post_id_comment == postsPtr[j].post_id)
		{
			temp = 1;
			pos = j;
			break;
		}
	}
	//display
	if (temp == 0) {
		cout << "Invalid post-ID!\n";
	}
	else {
		//post is shown first
		cout << "\nThe post with ID " << post_id_comment << " is: \n";
		if (pos > 9 && pos <= 19) {
			if (pos == 10)
				pages_pos = 0;
			else if (pos == 11)
				pages_pos = 1;
			else if (pos == 12)
				pages_pos = 2;
			else if (pos == 13)
				pages_pos = 3;
			else if (pos == 14)
				pages_pos = 4;
			pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
		}
		else if (pos <= 9) {
			usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
		}
		postsPtr->display_posts(postsPtr, size, pos, usersPtr);
		//comment is searched first
		size_t searched; int temp1 = 0, pos1 = 0;
		for (int j = 0; j < 10; j++)
		{
			searched = (postsPtr[pos].post_comments[j].find(" [your comment]"));
			if (searched != string::npos)
			{
				temp1 = 1;
				pos1 = j;
				break;
			}
		}
		if (temp1 == 1) {
			//comment is deleted
			if (!(postsPtr[pos].post_comments[pos1].empty())) {
				comment_not_empty = pos1;
				postsPtr[pos].post_comments[comment_not_empty] = "";
			}
		}
		else {
			//message is shown if no user comment is found
			cout << "\nYou haven't made a comment on the post with ID " << post_id_comment << endl << endl;
		}
		if (pos > 9 && pos <= 19) {
			if (pos == 10)
				pages_pos = 0;
			else if (pos == 11)
				pages_pos = 1;
			else if (pos == 12)
				pages_pos = 2;
			else if (pos == 13)
				pages_pos = 3;
			else if (pos == 14)
				pages_pos = 4;
			pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pages_pos);
		}
		else if (pos <= 9) {
			usersPtr->display_users(usersPtr, sizeOfUsersPtr, pos);
		}
		postsPtr->display_posts(postsPtr, size, pos, usersPtr);
	}
	cout << endl;
}
posts::~posts()
{
}

// pages class ///////////////////////////////////////////////////////////////////////////////////////////////////////
pages::pages()
{
	pages_title = "";
	pages_id = 0;
}
void pages::intialize_pages(pages* pagesPtr)
{
	//intialize titles
	pagesPtr[0].pages_title = "FAST-NU Community";
	pagesPtr[1].pages_title = "Food Fusion";
	pagesPtr[2].pages_title = "Netflix Pakistan";
	pagesPtr[3].pages_title = "International Cricket Council";
	pagesPtr[4].pages_title = "SpaceX";
	//initialize ids
	int pg_ids = 7010; /*a variable is used for initializing the pages IDs from 1-5*/
	for (int i = 0; i < 5; i++) {
		pagesPtr[i].pages_id = pg_ids;
		pg_ids++;
	}
	mydata << "-------List of Pages---------" << endl;
	for (int i = 0; i < 5; i++)
	{
		mydata << "<page>" << "\t" << pagesPtr[i].pages_id << "\t" << pagesPtr[i].pages_title << endl;
	}
}
void pages::display_pages(pages* pagesPtr, int& size, int& i)
{
	cout << "......................................................\n";
	cout << pagesPtr[i].pages_title << " (" << pagesPtr[i].pages_id << ") " << "shared a post with Post-ID ";
}
void pages::view_page(pages* pagesPtr, int& size, users* usersPtr, posts* postsPtr)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - VIEW A PAGE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	int temp = 0, pos = 0, page_id_view, posts_pos = 0;
	int sizeOfPagesPtr = 5;
	//user enters ID
	cout << "\nEnter page ID to view it: ";
	while (!(cin >> page_id_view))//Exception Handeled
	{
		cout << "Invalid Page ID!...\n" << "Enter page ID to view it: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	//ID is searched
	for (int j = 0; j < size; j++)
	{
		if (page_id_view == pagesPtr[j].pages_id)
		{
			temp = 1;
			pos = j;
			break;
		}
	}
	//display
	if (temp == 0) {
		cout << "Invalid page-ID!\n";
	}
	else {
		cout << "\nPage ID: " << pagesPtr[pos].pages_id;
		cout << "\nPage Title: " << pagesPtr[pos].pages_title;
		cout << "\nPosts made by " << pagesPtr[pos].pages_title << " are:\n";
		pagesPtr->display_pages(pagesPtr, sizeOfPagesPtr, pos);
		if (pos == 0)
			posts_pos = 10;
		else if (pos == 1)
			posts_pos = 11;
		else if (pos == 2)
			posts_pos = 12;
		else if (pos == 3)
			posts_pos = 13;
		else if (pos == 4)
			posts_pos = 14;
		postsPtr->display_posts(postsPtr, size, posts_pos, usersPtr);
	}
	cout << endl;
}
void pages::search_pages(pages* pagesPtr, int& size)
{
	cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - SEARCH A PAGE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	string search_key;
	size_t searched = -1;
	int temp = 0, pos = 0;
	//user enters search
	cout << "\nEnter search key: ";
	while (1)
	{
		try {
			while (!(cin >> search_key))
			{
				cout << "\nEnter search key: ";
				cin.clear();
				cin.ignore();
				throw "Invalid Input!";
			}
			break;
		}
		catch (const char y[]) //Exception Handeled
		{
			cout << y << endl;
			cout << "\nEnter search key: ";
		}
	}
	//it is searched in pages array
	for (int j = 0; j < size; j++)
	{
		searched = pagesPtr[j].pages_title.find(search_key);
		if (searched != string::npos) {
			temp = 1;
			pos = j;
			break;
		}
	}
	//display
	if (temp == 0)
		cout << "\nNo such pages found!\n";
	else
	{
		cout << "\nSearch found in pages...\n";
		cout << "Page name is " << pagesPtr[pos].pages_title << " with ID " << pagesPtr[pos].pages_id << endl;
	}
}
pages::~pages()
{

}