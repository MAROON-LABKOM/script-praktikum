# Hello
sudo apt -qq install figlet
figlet -f slant "MaroonLabkom"

# Update library
echo "Menginstall library..."
pip install --quiet --upgrade scikit-image

# Download sample file
echo "Mendownload file contoh..."
wget --quiet -O boneka.jpg "https://docs.google.com/uc?export=download&id=1rGok7TVnZShF6sFNlTgDhZgEdMLlUH6x"
wget --quiet -O daun.png "https://docs.google.com/uc?export=download&id=1SiTZGvMF2XXmHW4gPCLTz_KbFvzSArVP"
wget --quiet -O mobil.jpg "https://docs.google.com/uc?export=download&id=1GS5uIT4gEZsZyOm3M1m9YIV3Z7f7-FcI"
wget --quiet -O sel.tif "https://docs.google.com/uc?export=download&id=1EL8RO5wTgFV3MI6K0Pa00ZXg_fKR4VSX"

# Selesai
echo "HAPPY CODING <3"
