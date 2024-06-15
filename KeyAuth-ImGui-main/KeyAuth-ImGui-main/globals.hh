#pragma once
#include <unordered_map>
#include "auth/auth.hpp"
#include "skStr.h"

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = skCrypt("Loader").decrypt(); // Application Name
std::string ownerid = skCrypt("72zjngMKOB").decrypt(); // Owner ID
std::string secret = skCrypt("d524f856e4e19cf033efb6812bb9e748d6261c7dc9157175b9d4987a5ae19de5").decrypt(); // Application Secret
std::string version = skCrypt("1.0").decrypt();; // Application Version
std::string url = (std::string)skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);


class c_globals {
public:
	bool active = true;
	char username[255] = "";
	char password[255] = "";
	char key[255] = "";

	int tab = 0;;

    std::string CreateDate = tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.createdate)));
    std::string LastLogin = tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.lastlogin)));
    std::string Expiry = tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry)));
    std::string subs;
    
};

inline c_globals globals;



std::string tm_to_readable_time(tm ctx) {
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

    return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
    auto cv = strtol(timestamp.c_str(), NULL, 10); // long

    return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
    std::tm context;

    localtime_s(&context, &timestamp);

    return context;
}
