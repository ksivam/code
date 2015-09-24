using System;

namespace Fall2015
{
	class Node {

		public bool Visited { get; private set;}
		public int Value { get; private set;}
		public Node Left { get; private set;}
		public Node Right {get;private set;}

		public Node(int value) {
			this.Value = value;
		}

		public static void Print(Node node) {
			Console.WriteLine(node.Value);
		}

		public static void Visit(Node node){
			node.Visited = true;
		}
	}
}
