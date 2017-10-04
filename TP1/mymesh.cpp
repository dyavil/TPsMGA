#include "mymesh.h"

MyMesh::MyMesh()
{
    /*MyPoint p1 = MyPoint(0.5, 0.5, 0.5);
    MyPoint p2 = MyPoint(0.5, -0.5, 0.5);
    MyPoint p3 = MyPoint(0.5, 0.5, -0.5);

    sommets.push_back(p1);
    sommets.push_back(p2);
    sommets.push_back(p3);

    MyTriangle t1 = MyTriangle(0, 1, 2);
    triangles.push_back(t1);*/
    //load("cone.off");
    loadPoints("points.noff");
}

void MyMesh::draw(){
    glBegin(GL_POINTS);

    for( unsigned int i = 0; i < triangles.size(); i++ ) {
        glVertex3f(sommets[triangles[i].getTriangle().getP0()].getPoint().getX(), sommets[triangles[i].getTriangle().getP0()].getPoint().getY(), sommets[triangles[i].getTriangle().getP0()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP1()].getPoint().getX(), sommets[triangles[i].getTriangle().getP1()].getPoint().getY(), sommets[triangles[i].getTriangle().getP1()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP2()].getPoint().getX(), sommets[triangles[i].getTriangle().getP2()].getPoint().getY(), sommets[triangles[i].getTriangle().getP2()].getPoint().getZ());
    }

    glEnd();
}

void MyMesh::drawLine(){


    for( unsigned int i = 0; i < triangles.size(); i++ ) {
        glBegin(GL_LINE_STRIP);
        if(triangles[i].getTriangle().getP0() != 0 && triangles[i].getTriangle().getP1() != 0 && triangles[i].getTriangle().getP2() != 0){
        /*glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());
        glVertex3f(sommets[triangles[i].getP1()].getX(), sommets[triangles[i].getP1()].getY(), sommets[triangles[i].getP1()].getZ());
        glVertex3f(sommets[triangles[i].getP2()].getX(), sommets[triangles[i].getP2()].getY(), sommets[triangles[i].getP2()].getZ());
        glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());*/
        glVertex3f(sommets[triangles[i].getTriangle().getP0()].getPoint().getX(), sommets[triangles[i].getTriangle().getP0()].getPoint().getY(), sommets[triangles[i].getTriangle().getP0()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP1()].getPoint().getX(), sommets[triangles[i].getTriangle().getP1()].getPoint().getY(), sommets[triangles[i].getTriangle().getP1()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP2()].getPoint().getX(), sommets[triangles[i].getTriangle().getP2()].getPoint().getY(), sommets[triangles[i].getTriangle().getP2()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP0()].getPoint().getX(), sommets[triangles[i].getTriangle().getP0()].getPoint().getY(), sommets[triangles[i].getTriangle().getP0()].getPoint().getZ());
        }
        glEnd();
    }

}

void MyMesh::drawTriangle(){

    glBegin(GL_TRIANGLES);
    for( unsigned int i = 0; i < triangles.size(); i++ ) {
        /*glVertex3f(sommets[triangles[i].getP0()].getX(), sommets[triangles[i].getP0()].getY(), sommets[triangles[i].getP0()].getZ());
        glVertex3f(sommets[triangles[i].getP1()].getX(), sommets[triangles[i].getP1()].getY(), sommets[triangles[i].getP1()].getZ());
        glVertex3f(sommets[triangles[i].getP2()].getX(), sommets[triangles[i].getP2()].getY(), sommets[triangles[i].getP2()].getZ());*/
        glVertex3f(sommets[triangles[i].getTriangle().getP0()].getPoint().getX(), sommets[triangles[i].getTriangle().getP0()].getPoint().getY(), sommets[triangles[i].getTriangle().getP0()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP1()].getPoint().getX(), sommets[triangles[i].getTriangle().getP1()].getPoint().getY(), sommets[triangles[i].getTriangle().getP1()].getPoint().getZ());
        glVertex3f(sommets[triangles[i].getTriangle().getP2()].getPoint().getX(), sommets[triangles[i].getTriangle().getP2()].getPoint().getY(), sommets[triangles[i].getTriangle().getP2()].getPoint().getZ());

    }
    glEnd();
}

void MyMesh::debug(){



    for(unsigned int i = 0; i < triangles.size(); ++i){

        debugfile << "triangle id " << i << ", val : " << (triangles[i].getT0()) << ", " << (triangles[i].getT1()) << " , " << (triangles[i].getT2()) << "\n";

    }
    debugfile << "\n mid \n";


}

circulateur_de_faces MyMesh::faces_incidente(Sommet & v){
    circulateur_de_faces r = circulateur_de_faces(&triangles[v.getCorrespTriangle()], v, this);
    std::cout << "face t : " << v.getCorrespTriangle() << std::endl;
    r.getIdSommet();
    //r=r.debut();
    return r;
}

circulateur_de_sommets MyMesh::sommets_adjacents(Sommet & v){
    circulateur_de_sommets r = circulateur_de_sommets(&triangles[v.getCorrespTriangle()], v, this);
    r.getIdSommet();
    //r=r.debut();
    return r;
}

void MyMesh::load(std::__cxx11::string filename){
    debugfile.open("/home/dyavil/Documents/Master2/MaillageGeoAlgo/ToLoad/debug.txt");
    std::map<std::pair<unsigned int, unsigned int>, unsigned int> corresp;

    std::ifstream file;
    file.open("/home/dyavil/Documents/Master2/MaillageGeoAlgo/ToLoad/" + filename);
    std::string start;
    file >> start;
    unsigned int nbs, nbf, nbw;
    file >> nbs >> nbf >> nbw;
    float x0, y0, z0;
    for(unsigned int i = 0; i < nbs; i++){
        file >> x0 >> y0 >> z0;
        sommets.push_back(Sommet(MyPoint(x0, y0, z0), -1));
    }


    static int nbref1 = 0;
    static int nbref2 = 0;
    static int nbref3 = 0;
    for(unsigned int i = 0; i < nbf; i++){
        unsigned int s, id0, id1, id2;
        file >> s >> id0 >> id1 >> id2;
        unsigned int itr0 = -1;
        unsigned int itr1 = -1;
        unsigned int itr2 = -1;

        triangles.push_back(MyTriangleAug(MyTriangle(id0, id1, id2), -1, -1, -1));

        if(sommets[id0].getCorrespTriangle() == -1) sommets[id0].setCorrespTriangle(triangles.size()-1);
        if(sommets[id1].getCorrespTriangle() == -1) sommets[id1].setCorrespTriangle(triangles.size()-1);
        if(sommets[id2].getCorrespTriangle() == -1) sommets[id2].setCorrespTriangle(triangles.size()-1);

        //std::cout << id0 << ", " << id1 << ", " << id2 << std::endl;
        auto it = corresp.find(std::make_pair(std::min(id0, id1), std::max(id0, id1)));
        if(it != corresp.end()){
            itr0 = it ->second;

            nbref1 ++;
            //std::cout << std::min(id0, id1) << ", " << std::max(id0, id1) << ", ndref1 " << nbref1 << std::endl;
            triangles[it->second].addNeighbor(triangles.size()-1, std::min(id0, id1), std::max(id0, id1));
            triangles[triangles.size()-1].addNeighbor(it->second, std::min(id0, id1), std::max(id0, id1));
        }else{
            corresp.insert(std::pair<std::pair<unsigned int, unsigned int>, unsigned int>(std::make_pair(std::min(id0, id1), std::max(id0, id1)), triangles.size()-1));
        }
        ///////
        auto it2 = corresp.find(std::make_pair(std::min(id1, id2), std::max(id1, id2)));
        if(it2 != corresp.end()){
            itr1 = it2 ->second;
            nbref2 ++;
            triangles[it2->second].addNeighbor(triangles.size()-1, std::min(id1, id2), std::max(id1, id2));
            triangles[triangles.size()-1].addNeighbor(it2->second, std::min(id1, id2), std::max(id1, id2));
        }else{
            corresp.insert(std::pair<std::pair<unsigned int, unsigned int>, unsigned int>(std::make_pair(std::min(id1, id2), std::max(id1, id2)), triangles.size()-1));
        }
        ////////
        auto it3 = corresp.find(std::make_pair(std::min(id2, id0), std::max(id2, id0)));
        if(it3 != corresp.end()){
            itr2 = it3 ->second;
            nbref3++;
            triangles[it3->second].addNeighbor(triangles.size()-1, std::min(id2, id0), std::max(id2, id0));
            triangles[triangles.size()-1].addNeighbor(it3->second, std::min(id2, id0), std::max(id2, id0));
        }else{
            corresp.insert(std::pair<std::pair<unsigned int, unsigned int>, unsigned int>(std::make_pair(std::min(id2, id0), std::max(id2, id0)), triangles.size()-1));
        }


        //debug();
    }
    file.close();
    debugfile.close();
    unsigned int cc = 0;
    unsigned int cc2 = 0;
    unsigned int comp = -1;
    for(unsigned int i = 0; i < triangles.size(); i++){
        if(triangles[i].getT0() == comp) cc++;
        else cc2++;
        if(triangles[i].getT1() == comp) cc++;
        else cc2++;
        if(triangles[i].getT2() == comp) cc++;
        else cc2++;
    }


    unsigned int ksom = 0;
    int kmax = 0;


    sommet_iterator iit = sommet_begin();
    int i = 0;
    while (iit != sommet_end()) {
        ksom++;
        i++;
        circulateur_de_faces circu = faces_incidente(*iit);
        int cnt=0;
        circu = circu.debut();
        std::cout << i << "tourne " << iit->toString() << std::endl;
        std::cout << "start " << i << ", " << (*circu)->toString() << std::endl;
        do{
            std::cout << (*circu)->toString() << std::endl << std::endl;
            ++circu;
            cnt++;
        }while(circu!=circu.debut());

        std::cout << "last" << (*circu)->toString() << std::endl;

        std::cout << " end " << std::endl << std::endl << std::endl;
        kmax = std::max(kmax, cnt);
        iit->getPoint();
        iit++;
    }
    std::cout << ksom << "kmax : " << kmax << std::endl;


    std::cout << cc << "  ,  " << ksom << "  ,  " << nbref1 << "  ,  " << nbf << "  ,  " << triangles.size() << std::endl;
}

void MyMesh::loadPoints(std::__cxx11::string filename){

    std::ifstream file;
    Sommet infinite = Sommet(MyPoint(0, 0, -1), -1);
    sommets.push_back(infinite);
    file.open("/home/dyavil/Documents/Master2/MaillageGeoAlgo/ToLoad/" + filename);
    unsigned int nbs;
    file >> nbs;
    float x0, y0, z0;
    for(unsigned int i = 0; i < nbs; i++){
        file >> x0 >> y0 >> z0;
        sommets.push_back(Sommet(MyPoint(x0, y0, z0), -1));
    }
    file.close();
    triangulationInit();
}

void MyMesh::addPoint(unsigned int idTriangle, unsigned int p1){
    unsigned int oldp1 = triangles[idTriangle].getTriangle().getP1();
    triangles[idTriangle].getTriangle().setP1(p1);
    std::cout << "p 1 new = " << triangles[idTriangle].toString() << std::endl;
    unsigned int oldt0 = triangles[idTriangle].getT0();
    triangles[idTriangle].setT0(-1);
    unsigned int oldt2 = triangles[idTriangle].getT2();
    triangles[idTriangle].setT2(-1);
    unsigned int st = triangles.size()+1;
    triangles.push_back(MyTriangleAug(MyTriangle(p1, triangles[idTriangle].getTriangle().getP0(), oldp1), oldt2, st, idTriangle));
    triangles[idTriangle].setT2(triangles.size()-1);

    updateNeighbors(oldt2, idTriangle, triangles.size()-1);

    triangles.push_back(MyTriangleAug(MyTriangle(p1, oldp1, triangles[idTriangle].getTriangle().getP2()), oldt0, idTriangle, st-1));
    triangles[idTriangle].setT0(triangles.size()-1);
    sommets[p1].setCorrespTriangle(idTriangle);
    sommets[oldp1].setCorrespTriangle(triangles.size()-1);
    //maj point triangles[idTriangle].getTriangle().setP1(p1); pointeur
    updateNeighbors(oldt0, idTriangle, triangles.size()-1);

    std::cout << oldt0 << std::endl << std::endl;
    std::cout << triangles[idTriangle].toString() << std::endl << std::endl;
    std::cout << triangles[triangles.size()-2].toString() << std::endl << std::endl;
    std::cout << triangles[triangles.size()-1].toString() << std::endl << std::endl;

}

void MyMesh::updateNeighbors(unsigned int idtR, unsigned int idtO, unsigned int newid){
    if(triangles[idtR].getT0() == idtO) triangles[idtR].setT0(newid);
    else if(triangles[idtR].getT1() == idtO) triangles[idtR].setT1(newid);
    else if(triangles[idtR].getT2() == idtO) triangles[idtR].setT2(newid);

}

void MyMesh::addPointOut(unsigned int p0){
    std::vector<std::pair<unsigned int, unsigned int>> points;
    std::vector<MyTriangleAug *> tris;
    circulateur_de_faces circu = faces_incidente(*sommet_begin());

    int nbt = 0;
    circu = circu.debut();

    do{
        unsigned int p1, p2;
        if((*circu)->getTriangle().getP0() == 0){
            p1 = (*circu)->getTriangle().getP1();
            p2 = (*circu)->getTriangle().getP2();
        }else if((*circu)->getTriangle().getP1() == 0){
            p1 = (*circu)->getTriangle().getP2();
            p2 = (*circu)->getTriangle().getP0();
        }else{
            p1 = (*circu)->getTriangle().getP0();
            p2 = (*circu)->getTriangle().getP1();
        }
        MyPoint vec1 = sommets[p0].getPoint()-sommets[p1].getPoint();
        MyPoint vec2 = sommets[p0].getPoint()-sommets[p2].getPoint();
        MyPoint dir = vec1.prodVec(vec2);
        if(dir.getZ() > 0){
            nbt++;
            points.push_back(std::make_pair(p1, p2));
            tris.push_back(*circu);

        }
        ++circu;
    }while(circu != circu.debut());

    for(unsigned int i = 0; i < points.size(); i++){

        std::cout << "ouuuuuuuuuuuuut" << std::endl;
         std::cout << tris[i]->toString() << std::endl;
        unsigned int oldp1 = tris[i]->getTriangle().getP1();
        unsigned int oldt1 = tris[i]->getT1();
        /*tris[i]->getTriangle().setP1(tris[i]->getTriangle().getP2());
        tris[i]->getTriangle().setP2(oldp1);
        tris[i]->setT1(tris[i]->getT2());
        tris[i]->setT2(oldt1);*/
        tris[i]->getTriangle().setP0(p0);
        std::cout << tris[i]->toString() << "zemfzemflzmelf" << oldp1 << std::endl;
        /*triangles.push_back(MyTriangleAug(MyTriangle(p0, p2, p1), (*circu)->getT0(), st+1, st));

        triangles.push_back(MyTriangleAug(MyTriangle(0, p1, p0), st-1, st+1, (*circu)->getT1()));
        triangles.push_back(MyTriangleAug(MyTriangle(0, p0, p2), st-1, (*circu)->getT2(), st));*/
    }

    if(points.size() > 0){
        std::cout << "suuuuuuuuuuuuuuuuup0" << std::endl;
        unsigned int st = triangles.size()+1;
        unsigned int p1, p2;

        unsigned int nT2 = tris[0]->getT1();
        unsigned int nT1 = tris[tris.size()-1]->getT2();
        unsigned int inT2, inT1;


        if(tris.size()>1){
            inT2 = tris[1]->getT1();

        }
        else{
            inT2 = triangles[tris[0]->getT1()].getT2();
        }

        if(tris.size()>1) {
            inT1 = tris[tris.size()-2]->getT2();
        }
        else{
            inT1 = triangles[tris[0]->getT2()].getT1();

        }
        triangles[nT2].setT2(st-1);
        triangles[nT1].setT1(st);
         tris[0]->setT1(st-1);
         tris[tris.size()-1]->setT2(st);

        p1 = points[0].second;
        //maj des voisin au deux créérs
        p2 = points[points.size()-1].first;
        triangles.push_back(MyTriangleAug(MyTriangle(0, p0, p1), inT2, nT2, st));
        std::cout << triangles[triangles.size()-1].toString() << std::endl;
        triangles.push_back(MyTriangleAug(MyTriangle(0, p2, p0), inT1, st-1, nT1));
        std::cout << triangles[triangles.size()-1].toString() << std::endl;
        sommets[0].setCorrespTriangle(triangles.size()-2);
        sommets[p0].setCorrespTriangle(inT2);

        std::cout << "final 1 : " << tris[0]->toString() << std::endl;
        std::cout << "final 2 : " << tris[tris.size()-1]->toString() << std::endl;
    }
}

unsigned int MyMesh::inTriangle(MyPoint p1){
    unsigned int triangleId = -1;
    for(int i = 0; i < triangles.size(); ++i){
        bool cont = true;
        if(triangles[i].getTriangle().getP0() == 0 || triangles[i].getTriangle().getP1() == 0 || triangles[i].getTriangle().getP2() == 0) cont = false;
        std::cout << "test infinite 1 " << std::endl << std::endl;
        if (cont){
        MyPoint vec1 = p1-sommets[triangles[i].getTriangle().getP0()].getPoint();
        MyPoint vec2 = p1-sommets[triangles[i].getTriangle().getP1()].getPoint();
        MyPoint dir = vec1.prodVec(vec2);
        if(dir.getZ() < 0) cont = false;
            if(cont){
                vec1 = p1-sommets[triangles[i].getTriangle().getP1()].getPoint();
                vec2 = p1-sommets[triangles[i].getTriangle().getP2()].getPoint();
                dir = vec1.prodVec(vec2);
                if(dir.getZ() < 0) cont = false;
                if(cont){
                    vec1 = p1-sommets[triangles[i].getTriangle().getP2()].getPoint();
                    vec2 = p1-sommets[triangles[i].getTriangle().getP0()].getPoint();
                    dir = vec1.prodVec(vec2);
                    if(dir.getZ() < 0) cont = false;
                    else {
                        triangleId = i;
                        break;
                    }
                }
            }
        }
    }
    return triangleId;
}

////////////////////////
void MyMesh::maj(std::map<std::pair<unsigned int, unsigned int>, unsigned int> & corresp, unsigned int id0, unsigned int id1, unsigned int id2){
    unsigned int itr0 = -1;
    unsigned int itr1 = -1;
    unsigned int itr2 = -1;


    auto it = corresp.find(std::make_pair(std::min(id0, id1), std::max(id0, id1)));
    if(it != corresp.end()){
        itr0 = it ->second;

        //std::cout << std::min(id0, id1) << ", " << std::max(id0, id1) << ", ndref1 " << nbref1 << std::endl;
        triangles[it->second].addNeighbor(triangles.size()-1, std::min(id0, id1), std::max(id0, id1));
        triangles[triangles.size()-1].addNeighbor(it->second, std::min(id0, id1), std::max(id0, id1));
    }else{
        corresp.insert(std::pair<std::pair<unsigned int, unsigned int>, unsigned int>(std::make_pair(std::min(id0, id1), std::max(id0, id1)), triangles.size()-1));
    }
    ///////
    auto it2 = corresp.find(std::make_pair(std::min(id1, id2), std::max(id1, id2)));
    if(it2 != corresp.end()){
        itr1 = it2 ->second;
        triangles[it2->second].addNeighbor(triangles.size()-1, std::min(id1, id2), std::max(id1, id2));
        triangles[triangles.size()-1].addNeighbor(it2->second, std::min(id1, id2), std::max(id1, id2));
    }else{
        corresp.insert(std::pair<std::pair<unsigned int, unsigned int>, unsigned int>(std::make_pair(std::min(id1, id2), std::max(id1, id2)), triangles.size()-1));
    }
    ////////
    auto it3 = corresp.find(std::make_pair(std::min(id2, id0), std::max(id2, id0)));
    if(it3 != corresp.end()){
        itr2 = it3 ->second;
        triangles[it3->second].addNeighbor(triangles.size()-1, std::min(id2, id0), std::max(id2, id0));
        triangles[triangles.size()-1].addNeighbor(it3->second, std::min(id2, id0), std::max(id2, id0));
    }else{
        corresp.insert(std::pair<std::pair<unsigned int, unsigned int>, unsigned int>(std::make_pair(std::min(id2, id0), std::max(id2, id0)), triangles.size()-1));
    }
}
////////////////////////////////

void MyMesh::triangulationInit(){

    bool first = true;
    std::map<std::pair<unsigned int, unsigned int>, unsigned int> corresp;
    for (int i = 1; i < sommets.size(); ++i) {
        //premier triangle
        if(first){
            if(sommets.size() < 4 ) return;
            std::cout << "yolo " << sommets.size() << std::endl;
            MyPoint vec1 = sommets[i].getPoint()-sommets[i+1].getPoint();
            MyPoint vec2 = sommets[i].getPoint()-sommets[i+2].getPoint();
            MyPoint dir = vec1.prodVec(vec2);

            if(dir.getZ() > 0){
                triangles.push_back(MyTriangleAug(MyTriangle(i, i+1, i+2), 3, 1, 2));
                std::cout << "yolofrfrfrf " << sommets.size() << std::endl;
            }else triangles.push_back(MyTriangleAug(MyTriangle(i, i+2, i+1), 3, 2, 1));
            if(sommets[i].getCorrespTriangle() == -1) sommets[i].setCorrespTriangle(0);
            if(sommets[i+1].getCorrespTriangle() == -1) sommets[i+1].setCorrespTriangle(0);
            if(sommets[i+2].getCorrespTriangle() == -1) sommets[i+2].setCorrespTriangle(0);
            //maj(corresp, i, i+1, i+2);
            ///////test/////
            //0 1 3
             triangles.push_back(MyTriangleAug(MyTriangle(0, i, i+2), 0, -1, -1));

             maj(corresp, 0, i, i+2);
            // 0 2 1
            triangles.push_back(MyTriangleAug(MyTriangle(0, i+1, i), 0, -1, -1));
            maj(corresp, 0, i+1, i);


            //0 3 2
            triangles.push_back(MyTriangleAug(MyTriangle(0, i+2, i+1), 0, -1, -1));
            if(sommets[0].getCorrespTriangle() == -1) sommets[0].setCorrespTriangle(triangles.size()-1);
            maj(corresp, 0, i+2, i+1);




            //connexion au point infini
            /*maj(corresp, i, i+2, i+1);
            vec1 = sommets[0].getPoint()-sommets[i].getPoint();
            vec2 = sommets[0].getPoint()-sommets[i+1].getPoint();
            dir = vec1.prodVec(vec2);
            if(dir.getZ() < 0){
                triangles.push_back(MyTriangleAug(MyTriangle(0, i, i+1), -1, -1, -1));


            }else triangles.push_back(MyTriangleAug(MyTriangle(0, i+1, i), -1, -1, -1));
            if(sommets[0].getCorrespTriangle() == -1) sommets[0].setCorrespTriangle(triangles.size()-1);
            maj(corresp, 0, i, i+1);

            vec1 = sommets[0].getPoint()-sommets[i].getPoint();
            vec2 = sommets[0].getPoint()-sommets[i+2].getPoint();
            dir = vec1.prodVec(vec2);
            if(dir.getZ() < 0){
                triangles.push_back(MyTriangleAug(MyTriangle(0, i, i+2), -1, -1, -1));

            }else triangles.push_back(MyTriangleAug(MyTriangle(0, i+2, i), -1, -1, -1));

            maj(corresp, 0, i, i+2);


            vec1 = sommets[0].getPoint()-sommets[i+1].getPoint();
            vec2 = sommets[0].getPoint()-sommets[i+2].getPoint();
            dir = vec1.prodVec(vec2);
            if(dir.getZ() > 0){
                triangles.push_back(MyTriangleAug(MyTriangle(0, i+1, i+2), -1, -1, -1));

            }else triangles.push_back(MyTriangleAug(MyTriangle(0, i+2, i+1), -1, -1, -1));
            maj(corresp, 0, i+1, i+2);*/
            i += 2;
            first=false;
            std::cout << triangles[0].toString() << std::endl << std::endl;
            std::cout << triangles[1].toString() << std::endl << std::endl;
            std::cout << triangles[2].toString() << std::endl << std::endl;
            std::cout << triangles[3].toString() << std::endl << std::endl;
        }else{
            //ajout du reste des points

            unsigned int pos = inTriangle(sommets[i].getPoint());
            if(pos == (unsigned int)-1) {
                addPointOut(i);
                std::cout << "infinite" << std::endl;
            }
            else {
                addPoint(pos, i);

                std::cout << "insert in : " << pos << std::endl;
            }
        }

    }

    circulateur_de_sommets circu = sommets_adjacents(*sommet_begin());
    int cnt=0;
    bool infinite_loop = false;
    circu = circu.debut();
    std::cout << "start tourne " << ", " << circu.debut()->toString() << std::endl;
   do{
        std::cout << (*circu)->toString() << std::endl;
        if(cnt > 15) {
            std::cout << " break " << std::endl;
            infinite_loop =true;
            break;
        }
       ++circu;
        cnt++;
    }while(circu!=circu.debut());

    sommet_iterator iit = sommet_begin();

    int i = 0;
    //iit++;
    //iit++;
    //iit++;
    //iit++;
    while (iit != sommet_end()) {

        circulateur_de_faces circu = faces_incidente(*iit);
        int cnt=0;
        circu = circu.debut();
        std::cout << "start tourne " << i << ", " << circu.debut()->toString() << std::endl;
        do{
            std::cout << (*circu)->toString() << std::endl;
           ++circu;
            cnt++;
            if(cnt > 15) {
                std::cout << " break " << std::endl;
                infinite_loop =true;
                break;
            }
        }while(circu!=circu.debut());
        std::cout << i << "b, " << cnt << std::endl;
        std::cout << "end " << (*circu)->toString() << std::endl;
        circulateur_de_sommets circu2 = sommets_adjacents(*iit);
        cnt=0;

         std::cout << i << "tourne " << iit->toString() << std::endl;
        circu2 = circu2.debut();
        std::cout << i << "debut, " << (*circu2)->toString() << std::endl;
        do{
           ++circu2;
            cnt++;
            if(cnt > 15) {
                infinite_loop =true;
                break;
            }
            std::cout << "a, " << (*circu2)->toString() << std::endl;
        }while(circu2!=circu2.debut());
        std::cout << i << "end, " << (*circu2)->toString() << std::endl;
        std::cout << i << "a, " << cnt << std::endl;
        i++;
        iit++;
    }
    if(infinite_loop) std::cout << "innnnnnnnfinite looooooooooooooop" << std::endl;
}
