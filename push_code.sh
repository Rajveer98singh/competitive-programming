#!/bin/bash

# Check if a commit message was provided
if [ -z "$1" ]; then
  echo "Error: No commit message provided."
  echo "Usage: ./push_code.sh <commit-message>"
  exit 1
fi

COMMIT_MSG="$1"

echo "git status BEFORE pushing the code:"
git status

echo "Adding all the files by : git add ."
git add .

echo "git status after adding all the files by : git add ."
git status

echo "Committing the changes with message: $COMMIT_MSG"
git commit -m "$COMMIT_MSG"

echo "Pushing the changes to the remote repository..."
git push

echo -e "\e[32mCode pushed successfully!\e[0m"

echo "git status AFTER pushing the code:"
git status
