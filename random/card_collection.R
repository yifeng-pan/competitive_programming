# Problem:
# A card collection has 30 unique cards.
# The company sells packs that contains 2 cards each (1/30 chance for each card).
# Nav wants to collect all. 
# What is the expected number of packs for Nav to collect all cards?
# What is the sd?

# An approximation formula for the mean
# \mu \approx \frac{\sum_{k=1}^\infty {k (1-(29/30)^k)^{29}(29/30)^{k-1}} + 0.5}{2} \approx 60.1805
# min of some samples of a geometric distribution

x = c()
n = 10 * 1000

for(i in c(1:n)){
  cards = 30
  cards_left = 30
  cards_bought = 0
  
  while(cards_left > 0){
    cards_bought = cards_bought + rgeom(1, cards_left / cards) + 1
    cards_left = cards_left - 1
  }
  
  #Can only buy in pairs
  if(cards_bought %% 2 != 0) {
    cards_bought = cards_bought + 1
  }
  
  packs = cards_bought / 2
  x = c(x, packs)
}

cat("Mean:", mean(x), "from", n, "trials.\n")
cat("SD:", sd(x), "from", n, "trials.\n")