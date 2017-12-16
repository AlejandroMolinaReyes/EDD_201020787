#include "graficar.h"


Graficar::Graficar(colaDoble *colaAviones)
{
  QFile file(QDir::currentPath()+"/diagrama.txt");
  file.open(QIODevice::WriteOnly | QIODevice::Truncate);
  QTextStream text(&file);
  text << "digraph G {\n";
  text << " subgraph clusterAviones { label = \"Llegadas de aviones\";\n";
  nodoCola *aux = colaAviones->primero;
  while(aux!=0){
  Avion *avion = (Avion*)aux->datos;
  text << "     \"A" +QString::number(aux->posicion) + "\" [ label = \" Avion =A" + QString::number(aux->posicion) +"\\nPasajeros="+QString::number(avion->pajeros)+"\\nDesabordaje="+QString::number(avion->desabordaje)+"\\nMantenimiento="+QString::number(avion->mantenimiento)+"\"];\n";
      aux = aux->siguente;
  }
  text << "\n";
  aux = colaAviones->primero;
  while(aux!=0){
      if(aux->siguente!=0){
 text << "     A" + QString::number(aux->posicion) + "-> A" +QString::number(aux->siguente->posicion)+"\n";
      }
      if(aux->anterior!=0){
 text << "     A" + QString::number(aux->posicion) + "-> A" +QString::number(aux->anterior->posicion)+"\n";
      }
      aux = aux->siguente;
  }
  text << " }\n\n";
  text << " subgraph clusterDesabordaje {\n";
  text << "     label = \"Desabordaje\";\n";
  text << "     d -> f\n";
  text << " }\n";
  text << " subgraph clusterEscritorio {\n";
  text << "     label = \"Escritorios de registros\";\n";
  text << "     C -> D;\n";
  text << " }\n";
  text << " subgraph clusterEquipaje {\n";
  text << "     node [shape=\"box\"];\n";
  text << "     label = \"Equipaje\";\n";
  text << "     H -> L;\n";
  text << " }\n";
  text << " subgraph clusterMantenimiento {\n";
  text << "     label = \"Matenimiento\";\n";
  text << "     O -> P;\n";
  text << "     M -> N;\n";
  text << "     Y -> Z;\n";
  text << "     G -> S;\n";
  text << " }\n";
  text << "}\n";
  text << "\n";
  file.close();
  system("dot -Tjpg diagrama.txt -o diagrama.jpg");
}
