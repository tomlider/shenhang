#define _CRT_SECURE_NO_WARNINGS
#includestdio.h
#includestdlib.h
#includectype.h
#includealgorithm
#define INFINITY 65535
#define MAXVEX 100
using stdsort;
int parent[MAXVEX]; 记录某个顶点的 parent信息 
int count[MAXVEX];  记录子树规模  方便按秩归并 
typedef char VertexType;

typedef struct EData {
	int u, v;
	int weight;
}e_data;
e_data edges[MAXVEX]; 定义 边集合 

typedef struct ENode {
	int ivex;顶点 索引 
	int weight;
	struct ENode next_edge;
}ENode;

typedef struct VNode {
	VertexType data;  顶点 信息  
	ENode first_edge;
}VNode;

typedef struct Graph {
	VNode vex[MAXVEX];
	int vex_num, edge_num;
}Graph;

char read_char()
{
	char ch;
	do {
		ch = getchar();
	} while (!isalpha(ch));
	return ch;
}

int get_pos(Graph g, char ch)
{
	int i;
	for (i = 0; i  g.vex_num; i++) {
		if (ch == g.vex[i].data)
			return i;
	}

	return -1;
}

void link_last(ENode list, ENode last)
{
	ENode p;
	p = list;
	while (p-next_edge != NULL) {
		p = p-next_edge;
	}
	p-next_edge = last;
}
void create_graph(Graph g)
{
	int i;
	printf(请输入顶点数和边数n);
	scanf(%d %d, &g-vex_num, &g-edge_num);
	printf(请输入顶点信息n);
	for (i = 0; i  g-vex_num; i++) {
		g-vex[i].first_edge = NULL;
		char c;
		scanf(%c ,&c);
		g-vex[i].data = read_char();
			read_char();
	}
	int w;
	printf(请输入边 n);
	for (i = 0; i  g-edge_num; i++) {
		int p1, p2;
		char c1, c2;
		c1 = read_char();
		c2 = read_char();
		scanf(%d, &w);
		p1 = get_pos(g, c1);
		p2 = get_pos(g, c2);
		ENode node1,  node2;
		node1 = (ENode)malloc(sizeof(ENode));
		if (node1 == NULL) {
			printf(error);
			return;
		}
		node1-next_edge = NULL;
		node1-ivex = p2;
		node1-weight = w;
		if (g-vex[p1].first_edge == NULL)
			g-vex[p1].first_edge = node1;
		else
			link_last(g-vex[p1].first_edge, node1);
		node2 = (ENode)malloc(sizeof(ENode));
		node2-next_edge = NULL;
		node2-ivex = p1;
		node2-weight = w;
		if (g-vex[p2].first_edge == NULL)
			g-vex[p2].first_edge = node2;
		else
			link_last(g-vex[p2].first_edge, node2);
	}
}

int find_set(int x) 找到根节点 
{
	if (parent[x] == x)
		return x;
	return parent[x] = find_set(parent[x]); 路径压缩	提高查找效率 
}

bool cmp(e_data a, e_data b) 对边 按照权重进行排序 
{
	if (a.weight != b.weight)
		return a.weight  b.weight;
	else
		return a.u  b.u;如果 权重相同时 按照边起点序号排序		
}

void init_set(int i)
{
	parent[i] = i;
	count[i] = 1;起始 该树节点数为 1 
}

void union_set(int root1, int root2)
{
	if (root1 == root2)
		return;
	if (count[root1]  count[root2])
		parent[root2] = root1;
	else {
		if (count[root1] == count[root2])
			count[root2]++;
		parent[root1] = root2;
	}
}

void kruskal(Graph g)
{
	int i;
	int sum = 0;
	ENode p;
	int index = 0;

	for (i = 0; i  g.vex_num; i++) {
		p = g.vex[i].first_edge;
		while (p != NULL) {
			if (p-ivex  i) { 防止重复录入边 
				edges[index].u = i;
				edges[index].v = p-ivex;
				edges[index].weight = p-weight;
				index++;
			}
			p = p-next_edge;
		}
		init_set(i);初始化 顶点的根节点信息 
	}

	sort(edges, edges + g.edge_num, cmp);按照边的权重 从小到大排序	

	int root1, root2;
	for (i = 0; i  g.edge_num; i++) {
		root1 = find_set(edges[i].u);
		root2 = find_set(edges[i].v);

		if (root1 != root2) {
			sum += edges[i].weight;
			printf(%c--%c - %dn, edges[i].u + 'A', edges[i].v + 'A', edges[i].weight);
			union_set(root1, root2);
		}
	}

	printf(nmin_tree_ = %d, sum);
}

void print(Graph g)
{
	int i;
	ENode p;
	for (i = 0; i  g.vex_num; i++) {
		printf(%c, g.vex[i].data);
		p = g.vex[i].first_edge;
		while (p != NULL) {
			printf((%c, %c), g.vex[i].data, g.vex[p-ivex].data);
			p = p-next_edge;
		}
		printf(n);
	}
}

int main()
{
	system(color F0);
	Graph g;
	char ch1, ch2;
	create_graph(&g);
	int i;
	kruskal(g);
	printf(n);
		print(g);


	return 0;
}
