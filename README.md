# game-patterns
una raccolta di implementazione dei pattern piu comuni nel game dev

command-pattern
su una semplice implementazione di una finite-state-machine si dimostra l'applicazione del command pattern.

Da definizione il command pattern https://refactoring.guru/design-patterns/command

è un parttern comportamentale (behaviour) che trasforma una richiesta in un oggetto standalone che contiene tutte le informazioni della richiesta.

Questa trasformazione consente di passare le richieste come argomenti di un metodo, di ritardare o accodare l'esecuzione di una richiesta e di supportare operazioni reversibili.

l'obiettivo di questo progetto è quello di mostrare come disaccoppiare un bottone che triggera una transizione su una fsm, da un bottone che salva dati di profilo su file.


In generale quando si parla di interazione utente e quindi di UI è necessario disaccoppiare le logiche:

- GUI Layer

the GUI layer is responsible for rendering a beautiful picture on the screen, capturing any input and showing results of what the user and the app are doing. 

- logic layer
esecuzione della logica di business


Il command pattern si inserisce in questo contesto andando a creare il Command

The Command pattern suggests that GUI objects shouldn’t send these requests directly. Instead, you should extract all of the request details, such as the object being called, the name of the method and the list of arguments into a separate command class with a single method that triggers this request.





