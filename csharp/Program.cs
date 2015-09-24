using System;

namespace crack
{

	class Node {

		public bool Visited { get; private set;}
		public int Data { get; private set;}
		public Node Left { get; private set;}
		public Node Right {get;private set;}

		public Node(Node left, Node right, int data) {
			this.Data = data;
			this.Left = left;
			this.Right = right;
		}

		public static void Print(Node node) {
			Console.WriteLine(node.Data);
		}

		public static void Visit(Node node){
			node.Visited = true;
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			Node four = new Node(null, null, 4);
			Node five = new Node(null, null, 5);
			Node two = new Node (four, five, 2);

			Node six = new Node (null, null, 6);
			Node seven = new Node (null, null, 7);
			Node three = new Node (six, seven, 3);

			Node one = new Node (two, three, 1);

			// BFS queue
			var q = new List<Node> ();

		}

		public void BFS() {

		}
	}


}
