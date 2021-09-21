# Hello
sudo apt install figlet
figlet -f slant "MaroonLabkom"

# Update library
echo -e "\n=== Menginstall library...\n"
pip install --quiet --upgrade scikit-image

# Download sample file
echo -e "\n=== Mendownload file contoh...\n"
wget --quiet -o boneka.jpg https://docs.google.com/uc?export=download&id=1rGok7TVnZShF6sFNlTgDhZgEdMLlUH6x
wget --quiet -o daun.png https://docs.google.com/uc?export=download&id=1SiTZGvMF2XXmHW4gPCLTz_KbFvzSArVP
wget --quiet -o mobil.jpg https://docs.google.com/uc?export=download&id=1GS5uIT4gEZsZyOm3M1m9YIV3Z7f7-FcI
wget --quiet -o sel.tif https://docs.google.com/uc?export=download&id=1EL8RO5wTgFV3MI6K0Pa00ZXg_fKR4VSX

# Selesai
echo "\n=== HAPPY CODING ==="