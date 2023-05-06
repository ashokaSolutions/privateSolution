<html>
	<body>
		<%
			String str=request.getParameter("str");
			char[] c=str.toCharArray();
			for(int i=c.length-1;i>=0;i--)
				out.print(c[i]);
		%>
		
	</body>
</html>
				
