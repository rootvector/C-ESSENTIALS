gcc $1 -o $2 $(mysql_config --cflags --libs)

echo "Complied Success:"
