#!/bin/bash

# Delete the file if it exists
rm -f $1

# Create the output file:
touch $1


# Main loop
for i in $(eval echo {1..$2})
    do
        echo -e "$RANDOM $(pwgen -cn 100 1)">>$1
    done