echo 'Intializing git...'
git config --global user.name 'xue-zhiyu'
git config --global user.email 'xue_zhiyu@foxmail.com'

echo 'Testing ssh...'
cp -r /e/xuezy/.ssh/ ~/.ssh/
ssh -T git@github.com

echo 'Touching .bash_profile...'
cd ~
fname='.bash_profile'
if [ -f "$fname" ]
then
  rm $fname
fi
touch $fname
echo "alias l='ls -a'" >> $fname
echo "alias commit=$'git add .; git commit -m \'programs\'; git push origin main'" >> $fname
echo "cd /e/xuezy" >> $fname

echo 'Press [Enter] key to continue...'
read
