import subprocess
import csv
import datetime

log_file = 'lumax_doe_config1.csv'
timestamp = datetime.datetime.now()

# ping commands for Linux
pingcommands = [
    'ping -n 1 -l 8 1.1.1.1',
    'ping -n 1 -l 16 1.1.1.1',
    'ping -n 1 -l 32 1.1.1.1',
    'ping -n 1 -l 64 1.1.1.1',
    'ping -n 1 -l 128 1.1.1.1',
    'ping -n 1 -l 256 1.1.1.1',
    'ping -n 1 -l 512 1.1.1.1',
    'ping -n 1 -l 1024 1.1.1.1',
    'ping -n 1 -l 1500 1.1.1.1'
]

# create and open csv-file
with open(log_file, 'a', newline='\n') as csvfile:
    csvwrite = csv.writer(csvfile)

    for cmd in pingcommands:
        csvwrite.writerow([cmd])
        csvwrite.writerow([timestamp.strftime("%Y-%m-%d %H:%M:%S")])
        try:
            output = subprocess.run(cmd, capture_output=True, text=True, shell=True, timeout=5)
            csvwrite.writerow([output.stdout])

        except subprocess.CalledProcessError as e:
            print(f"Error occurred: {e}")
            csvwrite.writerow(["Error"])
csvfile.close()
