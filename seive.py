import numpy as np
import time

max_number = 1000000000

# array for results
arr = np.zeros(max_number, dtype='int8')

# starting time
t0 = time.time()

# some tracking for the time spent
time_spent = []

# go through all possible numbers up to the larges possible factor
for p in range(2, int(np.sqrt(max_number))):
    # if the number of factors for the number > 0, it is not a prime, jump to the next
    if arr[p] > 0:
        continue
    # if we have a prime, we will have to go through all its powers < max_number
    n = p
    while n < max_number:
         # increment the counter at n, 2n, 3n, ...
        arr[n::n] += 1
        # take the next power
        n = n * p
    # track the time spent

print "Time spent calculating the table of number of factors: {0} s".format(time.time()-t0)

# now we have the big primes left, but their powers are not needed any more
# they need to be taken into account up to max_number / 2
j = 0
for p in range(p + 1, (max_number + 1) / 2):
    if arr[p] > 0:
        continue
    arr[p::p] += 1
    if j % 10000 == 0:
        print "{0} at {1} s".format(p, time.time()-t0)
    j += 1

print "Primes up to {0} done at {1} s".format(p, time.time()-t0)
# now we have only big primes with no multiples left, they will be all 1
arr[arr == 0] = 1

print "Factor table done at {0} s".format(time.time() - t0)

# calculate the odd/even balance, note that 0 is not included and 1 has 0 factors
cumulative = np.cumsum(1 - 2 * (arr[1:] & 1), dtype='int32')
print "Total time {0} s".format(time.time()-t0)
