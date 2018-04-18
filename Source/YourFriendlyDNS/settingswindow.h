#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

/* YourFriendlyDNS - A really awesome multi-platform (lin,win,mac,android) local caching and proxying dns server!
Copyright (C) 2018  softwareengineer1 @ github.com/softwareengineer1
Support my work so I can keep bringing you great free and open software!
I'm going entirely 100% free software this year in 2018 (and onwards I want to) :)
Everything I make will be released under a free software license! That's my promise!
If you want to contact me another way besides through github, insert your message into the blockchain with a BCH/BTC UTXO! ^_^
Thank you for your support!
BCH: bitcoincash:qzh3knl0xeyrzrxm5paenewsmkm8r4t76glzxmzpqs
BTC: 1279WngWQUTV56UcTvzVAnNdR3Z7qb6R8j

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#include <QMainWindow>

/*MUST BLOCK:
http://sun.hac.lp1.d4c.nintendo.net:443 - System Update Server/Nag
http://beach.hac.lp1.eshop.nintendo.net:443 - System Update Nag/Eshop lockout

http://receive-lp1.dg.srv.nintendo.net
http://sun.hac.lp1.d4c.nintendo.net

hmmm... maybe we better implement some wildcards for extra safety... Done! :D

*.srv.nintendo.net
*.d4c.nintendo.net
* eshop.nintendo.net

OPTIONAL (May cause system instability):
http://aauth-lp1.ndas.srv.nintendo.net:443
http://accounts.nintendo.com:443 - Nintendo Account
http://api.accounts.nintendo.com:443 - Add Friends API
http://app-a04.lp1.npns.srv.nintendo.net:443
http://aqua.hac.lp1.d4c.nintendo.net:443
http://atum.hac.lp1.d4c.nintendo.net:443 - Game download server
http://bcat-data-lp1.cdn.nintendo.net:443
http://bcat-list-lp1.cdn.nintendo.net:443
http://broker.lp1.npns.srv.nintendo.net:443
http://bugyo.hac.lp1.eshop.nintendo.net:443 - eshop
http://consumer.lp1.npns.srv.nintendo.net:443 - eshop
http://dauth-lp1.ndas.srv.nintendo.net:443
http://e0d67c509fb203858ebcb2fe3f88c2aa.baas.nintendo.com:443 - Friends list
http://ecs-lp1.hac.shop.nintendo.net:443
http://pushmo.hac.lp1.eshop.nintendo.net:443 - eshop
http://receive-lp1.dg.srv.nintendo.net:443
http://receive-lp1.er.srv.nintendo.net:443 - error reporting
http://scontent.xx.fbcdn.net:443 - Facebook
http://superfly.hac.lp1.d4c.nintendo.net:443 - Game updates server
http://tagaya.hac.lp1.eshop.nintendo.net:443
http://web-lp1.share.srv.nintendo.net:443 - Facebook Image Posting
http://www.google-analytics.com:443 - Fsck you google! Stay out of my shit!
http://www.googletagmanager.com:443 - Google again? Really?
*/

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();
    QVector<QString> returnRealDNSServers();
    void clearDNSServers();
    bool isExisting(const QString &dns);
    void appendDNSServer(const QString &dns);
    void setRespondingIP(const QString &ip);
    QString getRespondingIP();
    void setCachedMinutesValid(quint32 minutesValid);
    quint32 getCachedMinutesValid();
    void setBlockOptionNoResponse();
    bool blockmode_localhost;

signals:
    void settingsUpdated();
    void clearDNSCache();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_option_localhost_clicked();
    void on_option_noresponse_clicked();
    void on_cacheValidMinutes_editingFinished();
    void on_respondingIP_editingFinished();
    void on_edit_dnsserver_returnPressed();
    void on_clearCacheButton_clicked();

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
