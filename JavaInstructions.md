# Setting up Java Development Environment


#### 1. Install the Java 8 SDK

##### Windows / MacOS X

- Download Link: [Oracle Java JDK Download](http://goo.gl/ZyTjr7)
- Add Java to Path
* Windows 10/8
1. In the search bar, search for `System`
2. Click the **Advanced System Settings link**.
3. Click **Environment Variables**. In *System Variables*, find the `PATH` variable and select it. If not found, click `New`.
4. In the **Edit System Variable** window, Add the `C:/Program Files/Java/jdku8__/bin` path.
5. Click Ok and restart.
6. Verify that it is added by opening Powershell/CMD and entering:

```
javac -version
java -version
```

* MacOS X
- added automatically
##### Linux

###### Ubuntu/Debian
- Run the following commands in terminal:

```
sudo add-apt-repository ppa:webupd8team/java
sudo apt-get update
sudo apt-get install oracle-java8-installer oracle-java-8-set-default
```

- Verify that Java is Installed using the following commands:

```
javac -v // To Check the Java Compiler
java -v // To Check the Java Runtime Environment
```

##### IDEs available for Java

There are a lot of different awesome IDE's available for Java

###### 1. BlueJ
For Someone only starting OOP, **BlueJ** is a great Light-weight IDE which helps define the OOP principles in an awesome matter.
- Download [here](https://bluej.org/)
- Installation instructions on the website

###### 2. Netbeans
For some reason, this is the choice for a lot of professionals. No idea why, if anyone does, please do tell!
- Download [here](https://netbeans.org/downloads/)

###### 3. Eclipse
Oh the goodness of Open Source. This Extensible IDE is the product of years of open source collaboration and is pretty cool. Add the extension of the language you wish to use, and it works!
Here's the thing though, it's way too complicated to set up and the learning curve is just weird. Give it a try :)
- Download [here](http://www.eclipse.org/downloads/packages/eclipse-ide-java-developers/oxygenr)

##### 4. IntelliJ IDEA
If there were any justice in the world, I'd have this guy on top!
This beauty is just brilliant! Life is so much easier with IDEA *ULTIMATE* by your side.
- Tons of Plugins
- Pretty Fast
- Hardly a learning curve.
- Tons of inbuilt Features
- Just plain awesome!
- Starting a project and getting to code literally takes 2 minutes.
- Use that Student email ID and get Ultimate edition for free as long as you have that ID!
- Download [here](https://www.jetbrains.com/idea/)

