library("igraph")
dat <- read.table("moo.txt", header = TRUE)
g <- graph.edgelist(as.matrix(dat))