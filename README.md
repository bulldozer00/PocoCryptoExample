# PocoCryptoExample
Contains source code that uses classes from the Poco.Crypto library

As of "now", the only way to build the executable is via the Eclipse CDT internal builder. Clone the tree, import it into Eclipse as "an existing Eclipse project", and click the build button.

From a command line shell, type

$ mkdir PocoCryptoExample

$ cd PocoCryptoExample

$ git clone https://github.com/bulldozer00/PocoCryptoExample.git

In Eclipse, select File/Import/General "import an existing project workspace". After the import, right-click on the project root directory and select "build"

The project depends on linking to PocoCrypto and PocoFoundation. It is also compiled as a cpp catch unit test executable. Ensure that Phil Nash's catch.hpp (https://github.com/philsquared/Catch) is in one of your include directory path (e.g. /usr/local/include) 
