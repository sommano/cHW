# Count lines with a;, ), or }, and let that count be named Lines.
Lines='[;)}]' *.c | wc -1`

# Now count how many lines there are in a directory listing; name it Files.
Files=`ls *.c |wc -1`

echo files=$Files and lines=$Lines

# Arithmetric expansion is a double-paren.
# In bash, the remainder is truncated; more on this later.
echo lines/file = $(($Lines/$Files))

# Or, use those variables in a here script.
# By setting scale=3, answers are printed to 3 decimal places.
bc << ---
scale=3
$Lines/$Files