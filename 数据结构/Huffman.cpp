#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Node {
  public:
    char c; //��ʾ�ַ�
    int frequency; //��ʾ���ַ����ֵĴ�����Ƶ��
    Node *left;
    Node *right;

    Node(char _c, int f, Node *l = NULL, Node *r = NULL)
      :c(_c), frequency(f), left(l), right(r) { }

    bool operator<(const Node &node) const { //����<���㷨�������ڼ������ȶ��е�ʱ�������δ�����λ��
      return frequency > node.frequency;
    }
};

void initNode(priority_queue<Node> &q, int nodeNum) {
  char c;
  int frequency;
  for (int i = 0; i < nodeNum; i++) {
    cout << "�����ַ��ͽ����ֵĴ���: ";
    cin >> c >> frequency;
    Node node(c, frequency);
    q.push(node);
  }
}

void showNode(priority_queue<Node> q) {
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    cout << node.c << ", " << node.frequency << endl;
  }
}

//�����������
void huffmanTree(priority_queue<Node> &q) {
  while (q.size() != 1) {
    Node *left = new Node(q.top()); q.pop();
    Node *right = new Node(q.top()); q.pop();

    Node node('R', left->frequency + right->frequency, left, right);
    q.push(node);
  }
}


// ��ӡ����������
void huffmanCode(Node *root, string &prefix, map<char, string> &result) {
  string m_prefix = prefix;

  if (root->left == NULL)
    return;

  //����������
  prefix += "0";
  //�����Ҷ�ӽ�������,����ݹ��ӡ������
  if (root->left->left == NULL)
    result[root->left->c] = prefix;
    //cout << root->left->c << ": " << prefix << endl;
  else
    huffmanCode(root->left, prefix, result);

  //��ԭԭ����·��,����
  prefix = m_prefix;

  //����������
  prefix += "1";
  //�����Ҷ�ӽ�㣬�����, ����ݹ��ӡ������
  if (root->right->right == NULL)
    result[root->right->c] = prefix;
    //cout << root->right->c << ": " << prefix << endl;
  else
    huffmanCode(root->right, prefix, result);

}

void testResult(map<char, string> result) {
  //����map����
  map<char, string>::const_iterator it = result.begin();
  while (it != result.end()) {
    cout << it->first << ": " << it->second << endl;
    ++it;
  }
}
int main() {
  priority_queue<Node> q;
  int nodeNum;

  //��ʼ���ַ���Ϣ
  cout << "�����������: ";
  cin >> nodeNum;
  initNode(q, nodeNum);
  //showNode(q);

  //�����������
  huffmanTree(q);

  //�������������
  Node root = q.top();
  string prefix = "";
  map<char, string> result;
  huffmanCode(&root, prefix, result);

  //�������Ƿ���ȷ
  testResult(result);
  return 0;
}

