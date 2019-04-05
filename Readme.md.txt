Rain water trapping problem


Here bar heights is available in a in an array . For example tower heights are {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1} .

For each tower we must find out a tower higher than it in the left side of it and if there exist a tower higher than it in the right side of it . If one of the tower is n't exist , we let that the place where the tower was , will not contain any water .

If there are  2 towers we can take highest one of left side and highest one of right side then we  take the minimum  of them . The unit where tower placed , totally will take that minimum number units of water .

On subtract the tower height from this minimum number , we will be find out how much water there will be for every unit of tower .

We take first index as first tower and last index as last tower of Scene will take no water because there are no tower where left of First tower and in the same way there are no tower  right of Last Tower.