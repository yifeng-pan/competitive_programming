#https://projecteuler.net/problem=13
#Solution: 5537376230


#Set work directory to source code directory
setwd(dirname(rstudioapi::getActiveDocumentContext()$path))

nums = read.table("100_numbers.txt")$V1
sumn = sum(nums)

n = sumn
while (n > 10^10)
  n = n / 10

print(n)