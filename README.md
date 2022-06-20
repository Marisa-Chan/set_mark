Simple override for applications that does not handle SO_MARK option.
This just forces socket to be marked with necessary mark.


Compile it with by running ``make.sh``

Run it like this ``LD_PRELOAD=/path/to/set_mark.so FORCE_MARK=your_mark curl http://....``
