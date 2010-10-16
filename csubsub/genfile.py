

import random


getchar = lambda : chr(97 + int(random.random()*25))


outmessage = [getchar() for i in range(100000)]
text = [getchar() for i in range(100)]

print "".join(outmessage)
print "".join(text)
