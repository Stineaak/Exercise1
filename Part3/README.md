# Reasons for concurrency and parallelism

 ### What is concurrency? What is parallelism? What's the difference?
 > "Concurrency is when two or more tasks can start, run, and complete in overlapping time periods. It doesn't necessarily mean they'll ever both be running at the same instant. For example, multitasking on a single-core machine.Parallelism is when tasks literally run at the same time, e.g., on a multicore processor."

// Kommentar: Skiller mellom mulighet og faktsik utførelse. 
 
 ### Why have machines become increasingly multicore in the past decade?
 > "The trend towards multiple cores is an engineering approach that helps the CPU designers avoid the power consumption problem that came with ever increasing frequency scaling. The computing power and clock frequency of a single processor reached their peak a few years ago, it just isn't easy to create more powerful and/or faster processors than the current ones; so the major CPU manufacturers (Intel, AMD) switched strategy and went multi-core...*"
 
 // Kommentar: Altså klarer vi ikke gjøre kjernene raskere enn de er uten å møte på større ulemper. Løsningen ble å heller å ha flere kjerner.
 
 ### What kinds of problems motivates the need for concurrent execution?
 (Or phrased differently: What problems do concurrency help in solving?)
 > Muligheten til å kjøre flere prosesser på en gang.
 
 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 > *..."This of course requires a lot more work from the application developers in order to harness the full power of multi-tasking: a program running on a single task just doesn't get any benefit from a multi-core CPU (although the system gets an overall bonus because it doesn't lock if a single process takes a single CPU to 100% usage)"
 
 //Kommentar: Dette kommer kanskje an på hvem man spør? Men det er uten tvil en design-utfordring
 
 ### What are the differences between processes, threads, green threads, and coroutines?
 > Prosseser innehar programkode og data og har en til flere tråder. Tråder har ikke data, men utfører programkoden til prosessen som eier den. Grønne tråder er tråder som blir "planlagt" (scheduled) av et bibliotek eller virtuell maskin. Grønne tråder avhenger ikke av OS'ets evene til å håndtere programmer/prosesser.

Coroutines er subrutioner (metoder, funksjoner, osv.) som gir fra seg kontroll over prosessor under veis i kjøringen.
 
 ### Which one of these do `pthread_create()` (C/POSIX), `threading.Thread()` (Python), `go` (Go) create?
 > pthread_create() oppretter en tråd.
 Threading.Thread() oppretter en OS kontrollert tråd, men noe spesielt pga GIL (global interpreter lock).
 Go oppretter coroutines som ligner på green threads, men det er en forskjell.
 
 ### How does pythons Global Interpreter Lock (GIL) influence the way a python Thread behaves?
 > Bare en tråd kan kjøre igangen, selv om det er flere kjerner på prosessoren.
 
 ### With this in mind: What is the workaround for the GIL (Hint: it's another module)?
 > En må kjøre flere python interpreters gjennom å benytte multiprocess modulen. For så å dele et minneområde mellom prosessene.
 
 ### What does `func GOMAXPROCS(n int) int` change? 
 > Setter maksgrense for hvor mange tråder som go corutinene kan fordeles over.
