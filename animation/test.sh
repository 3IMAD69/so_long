#!/bin/bash

# Specify the directory path
directory="/Users/idhaimy/Desktop/so_long/animation/death_scene/"

# Ensure the directory exists
if [ ! -d "$directory" ]; then
  echo "Directory not found: $directory"
  exit 1
fi

# Counter for naming
counter=0

# Loop through each file in the directory
for file in "$directory"/*; do
  # Check if the file is a regular file
  if [ -f "$file" ]; then
    # Create the new filename
    new_filename="${directory}/death_scene${counter}.xpm"
    
    # Rename the file
    mv "$file" "$new_filename"
    
    # Increment the counter
    ((counter++))
  fi
done

echo "Renaming complete!"
