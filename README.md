# RickZin021 - Gamemode Base Modular

Este é um projeto de gamemode base modular para San Andreas Multiplayer (SA-MP), desenvolvido com foco em organização, performance e facilidade de expansão. O sistema utiliza **SQLite** para armazenamento de dados e uma estrutura de módulos (.inc) para manter o código limpo.

## 🚀 Funcionalidades

- **Sistema de Autenticação**: Registro e Login integrados com TextDraws personalizadas.
- **Sistema de Spawn**: Controle preciso de última posição salva e spawn inicial.
- **Sistema de Atordoamento**: Mecânica de Roleplay onde o jogador fica atordoado por 4 minutos ao morrer, podendo ser socorrido pelo SAMU ou levado ao hospital.
- **Administração**: Comandos administrativos completos utilizando **IDF (ID Fixo)**.
- **Interface Visual**: Notificações personalizadas, telas de carregamento cinematográficas e etiquetas de identificação Nome [IDF].
- **Hierarquia Administrativa**: 9 níveis de cargos (do Jogador ao Fundador).

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: Pawn
- **Banco de Dados**: SQLite (a_sampdb)
- **Bibliotecas**: ZCMD, sscanf2, foreach.
- **Licença**: MIT

## 📂 Estrutura de Pastas

- `/gamemodes`: Arquivo principal (.pwn).
- `/modules`: Lógica modular dividida por sistemas (admin, player, textdraws, etc.).
- `/pawno`: Compilador e includes necessários.

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE]([LICENSE](https://github.com/rickcosta-dev/gamemode-base?tab=Apache-2.0-1-ov-file)) para mais detalhes.

---
**Desenvolvido por: RickZin021**  
**GitHub**: [https://github.com/rickcosta-dev](https://github.com/rickcosta-dev)  
**Repositório**: [https://github.com/rickcosta-dev/gamemode-base](https://github.com/rickcosta-dev/gamemode-base)
