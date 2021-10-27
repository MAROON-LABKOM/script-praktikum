# Hello
echo '    __  ___                             __          __    __                 '
echo '   /  |/  /___ __________  ____  ____  / /   ____ _/ /_  / /______  ____ ___ '
echo '  / /|_/ / __ `/ ___/ __ \/ __ \/ __ \/ /   / __ `/ __ \/ //_/ __ \/ __ `__ \'
echo ' / /  / / /_/ / /  / /_/ / /_/ / / / / /___/ /_/ / /_/ / ,< / /_/ / / / / / /'
echo '/_/  /_/\__,_/_/   \____/\____/_/ /_/_____/\__,_/_.___/_/|_|\____/_/ /_/ /_/ '

# Update library
echo "Menginstall library..."
pip install --quiet --use-feature=2020-resolver --disable-pip-version-check --upgrade scikit-image

# Download sample file
echo "Mendownload file contoh..."
wget --quiet -O boneka.jpg "https://docs.google.com/uc?export=download&id=1rGok7TVnZShF6sFNlTgDhZgEdMLlUH6x"
wget --quiet -O daun.png "https://docs.google.com/uc?export=download&id=1SiTZGvMF2XXmHW4gPCLTz_KbFvzSArVP"
wget --quiet -O mobil.jpg "https://docs.google.com/uc?export=download&id=1GS5uIT4gEZsZyOm3M1m9YIV3Z7f7-FcI"
wget --quiet -O sel.tif "https://docs.google.com/uc?export=download&id=1EL8RO5wTgFV3MI6K0Pa00ZXg_fKR4VSX"
wget --quiet -O tulisan.jpg "https://docs.google.com/uc?export=download&id=1g6xOlK5XrvHgAJNdHRVHgCwi1YZ8puqX"

# Done
echo "HAPPY CODING <3"
