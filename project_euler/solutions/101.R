#https://projecteuler.net/problem=101
#Solution: 37076114526

library(pracma) #for the RREF function
x = c(1:11) #f(x) is an 11th degree poly, only need first 11 terms
fx = 1 - x + x^2 - x^3 + x ^4 - x^5 + x^6 - x^7 + x^8 - x^9 + x^10
constant_term = 1

#Generates a matrix for Polynomial Interpolation
poly_matrix = function(n, fx){
  v = c(1:n)
  m = c()
  for(j in c(0:(i - 1))){
    m = c(m, v^j)
  }
  m = c(m, fx[1:i])
  return(matrix(nrow = n, m))
}

#RREF function didn't work on 1 by 2 matrix
#Have to set the first FIT manually
FITs = constant_term

#also why it's not c(1:10)
for (i in c(2:10)){
  m = poly_matrix(i, fx)
  m = rref(m)
  
  poly = m[,ncol(m)]
  gx = 0
  for(j in c(1:nrow(m))){
    gx = gx + poly[j]*x^(j-1)
  }
  
  #diff is a vector where g(x) and f(x) differs.
  #if the for loop was set to c(2:11) on i == 11, diff would be null
  #as g(x) == f(x)
  diff = gx[gx != fx]
  FITs = FITs + diff[1]
}

print(FITs)