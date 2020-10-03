**BSQ | by jrandee and oscalamar**
==
**Map Rules**
--
The first line of the map contains information on how to read the map:
```
[The number of lines on the map][The "empty" character][The "obstacle" character][The "full" character]
```
**Task**
--
Recreate map with "full" characters so that it composes the biggest possible square within the "obstacle" boundaries.

**Initial map**
```
%>cat example_file
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

In the case that more than one solution exists, we’ll choose to represent the
square that’s closest to the top of the map, then the one that’s most to the
left.

**Solution**
```
%>./bsq example_file
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
```
----
**OUR SOLUTION**
--
1) Parse arguments
	* argc = 1
		* Read from stdin
	* argc > 1
		* while (*argv) do job
2) Validate map
	* First line pattern validation. size, empty, obstacle, full


**MAP**
--
```c
map[int][int] = char;

while (i < lines)
	j = 0;
	while (j < columns)
		if (!(obstacle = ft_found(map, square.start, square.end)))
			start = map[i][j];
			ft_create_square(start)
			map[0][0] -> map[0][5] -> map[1][0]
			map[1][1] -> map[1][6] -> map[2][1]
			map[2][2] -> map[2][7] -> map[3][2]
			map[3][3]
			map[4][4]
			map[5][5]
			square.end = map[][]
			break ;
		j++;
	i++;
```

**FUNCS**
--

**NAME**
```c

```
**NAME**
```c

```
**NAME**
```c

```
**NAME**
```c

```