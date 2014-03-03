echo "*******Code with side effects*******"

cat test_file | ./side_effects

echo "*******Code without side effects****"

cat test_file | ./no_side_effects
