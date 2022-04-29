#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
using namespace std;

int main(){
    std::ofstream file("film_5.json");
    nlohmann::json dict = {
            {"Inseption", {
                    {"Country", "USA"},
                    {"Date", "2010"},
                    {"Production companies", "Legendary Pictures"},
                    {"Direct", "Christopher Nolan"},
                    {"Screenwriter", "Christopher Nolan"},
                    {"Producer", "Emma Thomas"},
                    {"Actors", {
                            {"Leonardo DiCaprio", "Dom Cobb"},
                            {"Joseph Gordon-Levitt", "Arthur"},
                            {"Elliot Page", "Ariadne"},
                            {"Tom Hardy", "Eames"},
                            {"Ken Watanabe", "Mr. Saito"},
                            {"Marion Cotillard", "Mal Cobb"},
                            {"Cillian Murphy", "Robert Michael Fischer"}}}}},
            {"Interstellar", {
                    {"Country", "USA"},
                    {"Date", "2014"},
                    {"Production companies", "Paramount Pictures"},
                    {"Direct", "Christopher Nolan"},
                    {"Screenwriter", "Christopher Nolan"},
                    {"Producer", "Emma Thomas"},
                    {"Actors", {
                            {"Matthew McConaughey", "Joseph Cooper"},
                            {"Ann Hathaway", "Amelia Brand"},
                            {"Jessica Chastain", "Murphy Cooper"},
                            {"Michael Caine", "Professor John Brand"},
                            {"Matt Damon", "Professor Mann"},
                            {"Bill Irwin", "TARS"},
                            {"Josh StewartCASE", "CASE"}}}}},
            {"The Lord of the Rings: The Return of the King",  {
                    {"Country", "New Zealand"},
                    {"Date", "2003"},
                    {"Production companies", "New Line Cinema"},
                    {"Direct","Peter Jackson"},
                    {"Screenwriter", "by J.R.R Tolkien"},
                    {"Producer", "Barrie M. Osborne"},
                    {"Actors", {
                            {"Elijah Wood", "Frodo Baggins"},
                            {"Ian McKellen", "Gandalf the White"},
                            {"Sean Astin", "Samwise Gamgee"},
                            {"Viggo Mortensen", "Aragorn Elessar"},
                            {"Orlando Bloom", "Legolas Greenleaf"},
                            {"John Rhys-Davies", "Gimli"},
                            {"Andy Serkis", "Gollum"}}}}},
            {"The Revenant",  {
                    {"Country", "USA"},
                    {"Date", "2015"},
                    {"Production companies", "Regency Enterprises"},
                    {"Direct","Alejandro G. Iñárritu"},
                    {"Screenwriter", "Mark L. Smith"},
                    {"Producer", "Arnon Milchan, Alejandro G. Iñárritu, Steve Golin"},
                    {"Actors", {
                            {"Leonardo DiCaprio", "Hugh Glass"},
                            {"Tom Hardy", "John Fitzgerald"},
                            {"Domhnall Gleeson", "Andrew Henry"},
                            {"Will Poulter", "Jim Bridger"},
                            {"Forrest Goodluck", "Hawk"},
                            {"Paul Anderson", "Anderson"},
                            {"Bear", "Bear"}}}}},
            {"The Prestige",  {
                    {"Country", "USA, UK"},
                    {"Date", "2006"},
                    {"Production companies", "Warner Bros. pictures"},
                    {"Direct","Christopher Nolan"},
                    {"Screenwriter", "Christopher Nolan"},
                    {"Producer", "Emma Thomas"},
                    {"Actors", {
                            {"Christian Bale", "Alfred \"The Professor\" Borden / Bernard Fallon / Freddy Borden"},
                            {"Hugh Jackman", "Robert \"The Great Danton\" Angier / Lord Caldlow"},
                            {"Michael Caine", "John Cutter"},
                            {"Scarlett Johansson", "Olivia Wenscombe"},
                            {"Piper Perabo", "Julia McCullough"},
                            {"Rebecca Hall", "Sarah Borden"},
                            {"David Bowie", "Nikola Tesla"}}}}}
            };
    file << dict;
    file.close();
}