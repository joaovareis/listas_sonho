class Playlist:

    def __init__(self, name):
        
        self.nome_playlist = name
        self.lista_musicas = []

    def add_music(self, music_name):

        self.lista_musicas.append(music_name)

    def remove_music(self, music_name):

        self.lista_musicas.remove(music_name)

    def play_next(self):
            
        self.remove_music(self.lista_musicas[0])

        if (len(self.lista_musicas)> 0):
            
            return self.lista_musicas[0]
        
        else: return "Nenhuma"
    
    def __str__(self):
        
        return f"Playlist: {self.nome_playlist}\nN° de Músicas: {len(self.lista_musicas)}\n"
    

minha_playlist = Playlist('MPB')

musicas = ["Lumiar - Beto Guedes",
           "Dia de Santos e Silvas - Gonzaguinha",
           "Pauapixuna - Fafá de Belém",
           "Bem que se quis - Marisa Monte",
           "Bandolins - Oswaldo Montenegro"]

for musica in musicas:
    minha_playlist.add_music(musica)

print(minha_playlist)

for musica in musicas:
    print(f"Tocando: {minha_playlist.play_next()}")

#O exerício não pede que retorne a primeira música e define que o play_next retorne a próxima.
#Logo, nunca iremos printar a primeira, "Lumiar"