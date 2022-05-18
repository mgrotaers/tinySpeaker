# tinySpeaker
ATtiny85 used to generate sound through speaker

# *Sound Model*
The sound equation used to create a music note used is:
    y = A sin(2 pi f t), where
        A is the amplitude or volume of the sound.
        f is the frequency of the music note.
        t is the time.
        y is the output to the speaker.
        
# *ATtiny85 Inputs*
Pin 7 (PB2) will be used as ADC1 producing a value between 0 to 1024 from a potentiometer.
Frequency of sound will be generated in the program on a time delay and will have the following frequencies:
    - 440Hz (Middle C)
    - 880Hz
    - 1760Hz

# *ATtiny65 Outputs*
Pin 3 (PB4 / OC1B) will send output to the speaker by a PWM signal.
