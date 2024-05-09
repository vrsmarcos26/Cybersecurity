#Capture Screan

import mss
import time

with mss.MSS() as sct:
    while True:
        last_time = time.time()
        img = sct.grab(sct.monitors[1])  # Change the monitor index if needed
        screenshot = Image.frombytes('RGB', img.size, img.bgra, 'raw', 'BGRX')
        screenshot.save('screenshot.png')
        print(f'Captured screenshot at {time.time() - last_time} seconds')
        time.sleep(5)  # Capture every 5 seconds