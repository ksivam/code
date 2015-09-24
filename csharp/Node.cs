using System;

namespace Fall2015
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
}
