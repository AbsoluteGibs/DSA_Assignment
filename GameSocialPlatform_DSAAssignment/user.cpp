#include "User.h"

// Constructors
// Always good to have a default constructor :> its a good coding practice apparently
User::User () { accountBalance = 0; }
User::User (string n, string b, string p) {
	name = n;
	bio = b;
	password = p;
	accountBalance = 0;
}

void User::editBio () {
	string newBio;
	cout << "Enter a bio: ";
	cin >> newBio;
	bio = newBio;
}

void User::viewProfile () {
	cout << "Username:" << name << endl << "Bio: " << bio << endl;
}

void User::topUpBalance (float amt) {
	accountBalance += amt;
}
float User::getBalance () { return accountBalance; }