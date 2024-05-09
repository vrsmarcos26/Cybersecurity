#Captura de áudio

import sounddevice as sd
import time

fs = 44100  # Sample rate
duration = 10  # Duration in seconds

audio = sd.rec(int(fs * duration), samplerate=fs, channels=2)
sd.wait()  # Wait until recording is finished
sd.play(audio)  # Play back the recording

# Save the audio to a file
import wave
wav_file = wave.open('audio.wav', 'wb')
wav_file.setnchannels(audio.ndim - 1)
wav_file.setsampwidth(audio.itemsize)
wav_file.setframerate(fs)
wav_file.writeframes(b''.join(audio))
wav_file.close()