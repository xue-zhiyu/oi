#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <utility>

template<typename Ta, typename Tb>
using Pair = std::pair<Ta, Tb>;

template<int L, typename Type>
class Vector {
public:
	Vector() {
	}

	Vector(const Vector& other) {
		for (int i = 0; i < L; i++) dat[i] = other.dat[i];
	}

	Vector(Type val) {
		for (int i = 0; i < L; i++) dat[i] = val;
	}

	Vector(std::initializer_list<Type> tmp) {
		auto it = tmp.begin();
		for (int i = 0; i < L; i++, it++) dat[i] = *it;
	}

	Type& operator[](int index) {
		if (index < 0 || index >= L) exit(114514);
		return dat[index];
	}

	void operator=(const Vector& other) {
		for (int i = 0; i < L; i++) dat[i] = other.dat[i];
	}

	bool operator==(const Vector& other) {
		for (int i = 0; i < L; i++)
			if (dat[i] != other.dat[i])
				return false;
		return true;
	}

	friend std::ostream& operator<<(std::ostream& output, const Vector<L, Type> vec) {
		output << '[';
		for (int i = 0; i < L; i++) output << vec.dat[i] << (i == L - 1 ? "" : ", ");
		output << ']';
		return output;
	}

private:
	Type dat[L];
};

template<int K, int N>
class KDTree {
public:
	using Position = Vector<K, int>;

	KDTree() : root(nullptr) {
	}

	friend std::ostream& operator<<(std::ostream& output, const KDTree<K, N>& tree) {
		output << "Printing:" << std::endl;
		tree._print(output, tree.root, 0);
		return output;
	}

	void insert(Position pos, int val) {
		if (root == nullptr) {
			root = pool.get();
			root->id = ++cid;
			root->fg = 0;
			root->val = val;
			root->pos = pos;
			root->lson = root->rson = nullptr;
			root->pushup();
			return;
		}
		insertInsert(root, nullptr, pos, val);
		insertRebuild(root, pos);
	}

	int query(Position posa, Position posb) {
		return _query(root, posa, posb);
	}

private:
	static constexpr double alpha = 0.6;

	KDTree(const KDTree& other) : root(nullptr) {
	}

	void operator=(const KDTree& other) {
	}

	class Node {
	public:
		Node() : id(0) , val(0), pos(0), sum(0), siz(0), fg(0), lson(nullptr), rson(nullptr), fat(nullptr), lpos(0), rpos(0) {
		}

		Node(const Node& other) : id(other.id), val(other.val), pos(other.pos), sum(other.sum), siz(other.siz), fg(other.fg), lson(other.lson), rson(other.rson), fat(other.fat), lpos(other.lpos), rpos(other.rpos) {
		}

		void operator=(const Node& other) {
			id = other.id, val = other.val, pos = other.pos, sum = other.sum, siz = other.siz;
			fg = other.fg, lson = other.lson, rson = other.rson, lpos = other.lpos, rpos = other.rpos;
		}

		void pushup() {
			sum = val, siz = 1;
			lpos = pos, rpos = pos;
			if (lson != nullptr) {
				sum += lson->val, siz += lson->siz;
				for (int i = 0; i < K; i++) lpos[i] = std::min(lpos[i], lson->lpos[i]);
				for (int i = 0; i < K; i++) rpos[i] = std::max(rpos[i], lson->rpos[i]);
			}
			if (rson != nullptr) {
				sum += rson->val, siz += rson->siz;
				for (int i = 0; i < K; i++) lpos[i] = std::min(lpos[i], rson->lpos[i]);
				for (int i = 0; i < K; i++) rpos[i] = std::max(rpos[i], rson->rpos[i]);
			}
		}

		friend std::ostream& operator<<(std::ostream& output, const Node& cur) {
			output << "At[" << cur.id << "]={{val=" << cur.val << ", pos=" << cur.pos << "}, {sum=" << cur.sum << ", siz=" << cur.siz << ", fg=" << cur.fg << ", fat=" << (cur.fat == nullptr ? 0 : cur.fat->id) << ", lsonid=" <<
					(cur.lson == nullptr ? 0 : cur.lson->id) << ", rsonid=" << (cur.rson == nullptr ? 0 : cur.rson->id) << ", lpos=" << cur.lpos << ", rpos=" << cur.rpos << "}}" << std::endl;
			return output;
		}

		int id;

		int val;
		Position pos;

		int sum, siz, fg;
		Node *lson, *rson, *fat;
		Position lpos, rpos;
	};

	class NodePool {
	public:
		NodePool() : top(0), idx(0) {
			pool = new Node[N + 10];
			for (int i = 0; i < N + 10; i++) pool[i].id = i + 1;
		}

		void push(Node *val) {
			can[++top] = val;
		}

		Node* get() {
			if (top) {
				return can[top--];
			}
			return &pool[idx++];
		}

	private:
		int top, idx;
		Node *can[N + 10], *pool;
	};

	Node* root;
	NodePool pool;

	void _print(std::ostream& output, const Node* cur, int ceng) const {
		if (cur == nullptr) return;
		for (int i = 0; i < ceng; i++) output << '-';
		output << (*cur);
		_print(output, cur->lson, ceng + 1);
		_print(output, cur->rson, ceng + 1);
	}

	int rebuildTop, cid;
	Vector<N + 10, int> rebuildId;
	Vector<N + 10, Pair<Position, int>> rebuildTmp;

	void rebuildExpand(Node* cur) {
		if (cur == nullptr) return;
		rebuildExpand(cur->lson);
		rebuildTmp[++rebuildTop] = {cur->pos, cur->val};
		rebuildId[rebuildTop] = cur->id;
		pool.push(cur);
		rebuildExpand(cur->rson);
	}

	Node* rebuildBuild(int l, int r, int curfg, Node* fat) {
		if (l > r) return nullptr;
		if (l == r) {
			Node* cur = pool.get();
			cur->id = rebuildId[l];
			cur->fg = curfg;
			cur->val = rebuildTmp[l].second;
			cur->pos = rebuildTmp[l].first;
			cur->fat = fat;
			cur->lson = cur->rson = nullptr;
			cur->pushup();
			return cur;
		}
		int mid = (l + r + 1) >> 1;
		std::nth_element(&(rebuildTmp[l]), &(rebuildTmp[mid]), &(rebuildTmp[r + 1]), [&](Pair<Position, int> a, Pair<Position, int> b) { return a.first[curfg] < b.first[curfg]; });
		Node* cur = pool.get();
		cur->id = rebuildId[mid];
		cur->fg = curfg;
		cur->val = rebuildTmp[mid].second;
		cur->pos = rebuildTmp[mid].first;
		cur->fat = fat;
		cur->lson = rebuildBuild(l, mid - 1, curfg ^ 1, cur);
		cur->rson = rebuildBuild(mid + 1, r, curfg ^ 1, cur);
		cur->pushup();
		return cur;
	}

	void rebuild(Node* cur) {
		int curfg = cur->fg;
		if (cur == root) {
			rebuildTop = 0;
			rebuildExpand(cur);
			root = rebuildBuild(1, rebuildTop, curfg, nullptr);
		} else {
			rebuildTop = 0;
			rebuildExpand(cur);
			Node *fat = cur->fat;
			if (fat->lson == cur) {
				fat->lson = rebuildBuild(1, rebuildTop, curfg, nullptr);
			} else {
				fat->rson = rebuildBuild(1, rebuildTop, curfg, nullptr);
			}
		}
	}

	bool isNeedRebuild(Node* cur) {
		return (cur->lson != nullptr && cur->siz * alpha < cur->lson->siz * 1.)
			|| (cur->rson != nullptr && cur->siz * alpha < cur->rson->siz * 1.);
	}

	void insertInsert(Node* cur, Node* fat, Position& pos, int val) {
		if (cur == nullptr) {
			cur = pool.get();
			cur->fg = fat->fg ^ 1;
			cur->id = ++cid, cur->val = val, cur->pos = pos;
			cur->lson = cur->rson = nullptr, cur->fat = fat;
			if (pos[fat->fg] <= fat->pos[fat->fg]) fat->lson = cur;
			else fat->rson = cur;
			cur->pushup();
			return;
		}
		if (cur->pos == pos) {
			cur->val += val;
			cur->pushup();
			return;
		}
		if (pos[cur->fg] <= cur->pos[cur->fg]) insertInsert(cur->lson, cur, pos, val);
		else								   insertInsert(cur->rson, cur, pos, val);
		cur->pushup();
	}
	
	void insertRebuild(Node* cur, Position& pos) {
		if (cur == nullptr) return;
		if (isNeedRebuild(cur)) {
			rebuild(cur);
			return;
		}
		if (pos[cur->fg] <= cur->pos[cur->fg]) insertRebuild(cur->lson, pos);
		else								   insertRebuild(cur->rson, pos);
	}

	int _query(Node* cur, Position& posa, Position& posb) {
		if (cur == nullptr) return 0;
		bool flag = true;
		for (int i = 0; i < K; i++) flag = flag && (posa[i] <= cur->lpos[i] && cur->rpos[i] <= posb[i]);
		if (flag) return cur->sum;
		flag = false;
		for (int i = 0; i < K; i++) flag = flag || (posa[i] > cur->lpos[i] || cur->rpos[i] > posb[i]);
		if (flag) return 0;
		int ans = 0;
		flag = true;
		for (int i = 0; i < K; i++) flag = flag && (posa[i] <= cur->pos[i] && cur->pos[i] <= posb[i]);
		if (flag) ans += cur->val;
		ans += _query(cur->lson, posa, posb);
		ans += _query(cur->rson, posa, posb);
		return ans;
	}
};

int n, lastans;
KDTree<2, 200000> tree;

int main() {
	std::cin >> n;
	while (true) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int x, y, val;
			std::cin >> x >> y >> val;
			x ^= lastans, y ^= lastans, val ^= lastans;
			tree.insert({x, y}, val);
		} else if (opt == 2) {
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			x1 ^= lastans, y1 ^= lastans;
			x2 ^= lastans, y2 ^= lastans;
			std::cout << (lastans = tree.query({x1, y1}, {x2, y2})) << std::endl;
		} else {
			break;
		}
	}
	return 0;
}

