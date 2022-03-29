<h2>Code Inserter C++</h2>
<p>This project was created with the aim of create c++ classes automatically, both the headers and their respective cpp.
The program must be executed as follows:</p>
<p><b>coder [readFile] [savePath] [1 = with CPP]</b></p>
<p><b>readFile:</b> Path of your C++ classes</p>
<p><b>savePath:</b> Directory where the files will be saved </p>
<p><b>1:</b> If the 4th parameter is 1. The coder will create cpp files and hpp files and with another value, the coder only create the hpp files</p>

<h3>Example</h3>
<h4>Filename: clases.txt</h4>
<p>class Persona</p>
<p>int edad</p>
<p>string nombre</p>
<p>string apellido</p>

<h4>OutPut Directory: "c:\user\test"</h4>
<h4>Without CPP</h4>

<p><b>coder clases.txt "c:\user\test"</b></p>
<p></p>
<p>The output will generate the Person header with its attributes and mutators</p>
