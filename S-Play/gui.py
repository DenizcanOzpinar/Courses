import os
import sys
import time
from tkinter import *
from functools import partial
from tkinter import messagebox
from tkinter.ttk import Progressbar

from functions import send, download_s3_folder


def exit_call_back(page):
    page.withdraw()
    return sys.exit()


def dir_call_back(src_entry):
    directory = (src_entry.get())
    send(directory)

    messagebox.showinfo(message="Upload completed")


def down_call_back(down_entry, alter_entry):
    directory = (down_entry.get())
    if len(alter_entry.get()) == 0:
        print("here")
        download_s3_folder(directory, directory)
    else:
        download_s3_folder(directory, alter_entry.get())
    messagebox.showinfo(message="Download completed")


def init_gui():
    #
    theme = 'white'
    root = Tk()
    root.title("S-play")
    root.geometry('650x300')
    root.configure(background=theme)
    # path for upload
    src_label = Label(root, text="Enter directory of save files to upload :   ")
    src_label.grid(row=1, column=1)
    src_label.configure(background=theme)
    src_entry = Entry(root, bd=2)
    src_entry.grid(row=1, column=2)
    src_entry.configure(background=theme)

    # path for download
    down_label = Label(root, text="Enter directory of save files to download: ")
    down_label.grid(row=2, column=1)
    down_label.configure(background=theme)
    down_entry = Entry(root, bd=2)
    down_entry.grid(row=2, column=2)
    down_entry.configure(background=theme)

    # Alternative file path
    alter_label = Label(root, text="Enter alternative path to save files to that location: ")
    alter_label.grid(row=3, column=1)
    alter_label.configure(background=theme)
    alter_entry = Entry(root, bd=2)
    alter_entry.grid(row=3, column=2)
    alter_entry.configure(background=theme)

    # Buttons
    dir_add = Button(root, text="Upload", fg="black", background=theme, command=partial(dir_call_back, src_entry))
    dir_add.grid(row=1, column=3)

    dir_add = Button(root, text="Download", fg="black", command=partial(down_call_back, down_entry, alter_entry))
    dir_add.grid(row=2, column=3)

    exit_button = Button(root, text="Exit", fg="black", command=partial(exit_call_back, root))
    exit_button.grid(row=4, column=2)

    root.resizable(False, False)
    root.mainloop()


init_gui()
