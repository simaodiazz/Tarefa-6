#pragma once

#include <functional>
#include <cstdarg>
#include "node.h"

using namespace std;

template <typename T>
class List {
private:
    int size = 0;
    Node<T>* header = nullptr;
    Node<T>* footer = nullptr;
public:

    /**
     * Construtor da classe para iniciar varios valores na lista
     * 
     * @author simaodiazz
     * @param lenght Tamanho da lista
     * @param ... Valores a serem adicionados
    */
    List(int lenght, ...) {
        va_list args;
        va_start(args, lenght);

        for (int i = 0; i < lenght; i++) {
            T element = va_arg(args, T);
            this->add(element);
        }
    }

    List() { }

    /**
     * Método para adquirir o tamanho da lista
     * 
     * @author simaodiazz
    */
    int getSize() {
        return size;
    }

    /**
     * Método para adicionar um novo elemento a lista
     * 
     * @author simaodiazz
     * @param data Valor a ser adicionado
    */
    void add(T data) {
        Node<T> *node = new Node<T>(data);

        if (size == 0) {
            this->header = node;
            this->footer = node;
        } else {
            node->prev = this->footer;
            this->footer->next = node;
            this->footer = node;
        }
        this->size++;
    }

    /**
     * Retorna o nó do comeco da lista
     * 
     * @author simaodiazz
    */
    Node<T>* getHeader() {
        return this->header;     
    }

    /**
     * Retorna o nó do final da lista
     * 
     * @author simaodiazz
    */
    Node<T>* getFooter() {
        return this->footer;
    }

    /**
     * Retorna um nó da lista pelo indice
     * 
     * @author simaodiazz
     * @param index Indice do nó
     * @param mode Modo (true = antecessor, false = sucessor)
    */
    Node<T>* get(int index, bool mode) {
        Node<T>* node = mode ? this->footer : this->header;
        for (int i = 0; i < index; i++) {
            node = mode ? node->prev : node->next;
        }
        return node;
    }

    /**
     * Remove um nó da lista pelo indice
     * 
     * @author simaodiazz
     * @param index Indice do nó
    */
    void remove(int index) {
        Node<T>* node = get(index, true);

        /**
         * Para evitar criar uma referência circular
         * Eu pensei em ir adquirir ao nó anterior e depois adquirir a varíavel next 
         * Já que são duas varíaveis independentes interligadas
        */
        node->prev->next = node->next;
        node->next->prev = node->prev;

        this->size--;
    }

    /**
     * Verificar se um elemento existe na lista
     * 
     * @author simaodiazz
     * @param data Valor a ser verificado
    */
    bool contains(T data) {
        Node<T>* node = this->header;
        while (node->next != nullptr) {
            if (node->data == data) return true;
            node = node->next;
        }
        return false;
    }

    /**
     * Função para percorrer todos os nós da lista
     * 
     * @author simaodiazz
     * @param callback função para retornar o nó atual a ser percorrido
    */
    void forEach(function<void(Node<T>*)> callback) {
        Node<T>* node = this->header;
        while (node->next != nullptr) {
            callback(node);
            node = node->next;
        }
    }
};
