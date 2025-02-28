git status
read -p '\nSure to submit?[yes]/no) ' opt
if test $[opt] -eq 'yes'
then
    echo 'ok'
else
    echo 'nok'
fi
