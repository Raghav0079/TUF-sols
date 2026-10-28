/*  You are given "N" cities. There are "M" roads - each of the "M" roads connects two different cities directly.
When you go by a car from city 'x' to city 'y' via any one of the "M" roads - it costs you 1kg of fuel.
The car starts from the 'source' city and the goal of the car is to reach the 'destination' city. Initially the car has 'P' kgs of fuel. Some cities have re-fueling stations in them - whenever you visit a city which has a re-fueling station in it - it is necessary to re-fuel your car to exactly 'P' kgs again. You are allowed to visit the same road multiple times. If you visit a road for 5 times - then it is counted as 5 times in the final answer as well. Source city will never be a station.
 
Your task is to go from 'source' city to 'destination' city -
1)First of all prioritize the fact that in your path you should never reach negative fuel at any point of time.
2)Secondly, prioritize visiting the minimum number of stations in the path.
3)Thirdly, prioritize using the minimum number of direct roads in your path.
Output {min_stations,min_roads} which you would have to go through to go from 'source' to 'destination' and if it is not possible to do - report that as well(as you might run out of fuel in the path)
*/


