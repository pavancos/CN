Here’s the Markdown formatting for each command from the PDF:

```markdown
# Basic Linux Network Commands

## 1. `hostname`
- **What it does**: Displays or sets the system hostname.
- **Syntax**:
  ```bash
  hostname
  ```
- **To set the hostname**:
  ```bash
  sudo hostname <newName>
  ```
  - This change is temporary; to make it permanent, edit `/etc/hostname`.

---

## 2. `ifconfig`
- **What it does**: Configures and displays network interfaces.
- **Syntax**:
  ```bash
  ifconfig
  ```
- **Get details of specific interface**:
  ```bash
  ifconfig <interface_name>
  ```
- **Assign IP address**:
  ```bash
  ifconfig eth0 <address> netmask <netmask>
  ```
- **Enable/disable an interface**:
  ```bash
  ifup eth0
  ifdown eth0
  ```

---

## 3. `ip`
- **What it does**: Replacement for `ifconfig`, used for network interface management.
- **Syntax**:
  ```bash
  ip a
  ```
- **Show details of specific interface**:
  ```bash
  ip a show <interface_name>
  ```

---

## 4. `traceroute`
- **What it does**: Traces the path packets take to reach a network host.
- **Syntax**:
  ```bash
  traceroute <destination>
  ```
- **Use without DNS lookup**:
  ```bash
  traceroute -n <destination>
  ```
- **Use ICMP packets**:
  ```bash
  sudo traceroute -I <destination>
  ```

---

## 5. `tracepath`
- **What it does**: Similar to `traceroute`, but doesn’t require root privileges.
- **Syntax**:
  ```bash
  tracepath <destination>
  ```

---

## 6. `ping`
- **What it does**: Checks connectivity between two nodes.
- **Syntax**:
  ```bash
  ping <destination>
  ```
- **Limit packet count**:
  ```bash
  ping -c <number> <destination>
  ```

---

## 7. `netstat`
- **What it does**: Displays network connections, routing tables, interface statistics, etc.
- **Syntax**:
  ```bash
  netstat
  ```
- **Display program names**:
  ```bash
  netstat -p
  ```
- **Show routing table**:
  ```bash
  netstat -r
  ```

---

## 8. `ss`
- **What it does**: Replacement for `netstat`, displays socket statistics.
- **Syntax**:
  ```bash
  ss
  ```
- **Show TCP connections**:
  ```bash
  ss -ta
  ```
- **Show listening TCP ports**:
  ```bash
  ss -lt
  ```

---

## 9. `dig`
- **What it does**: DNS lookup tool.
- **Syntax**:
  ```bash
  dig <domain>
  ```
- **Query MX records**:
  ```bash
  dig <domain> MX
  ```
- **Query all record types**:
  ```bash
  dig <domain> ANY
  ```

---

## 10. `nslookup`
- **What it does**: DNS query tool.
- **Syntax**:
  ```bash
  nslookup <domain>
  ```

---

## 11. `route`
- **What it does**: Displays or modifies the IP routing table.
- **Syntax**:
  ```bash
  route
  ```
- **Add default gateway**:
  ```bash
  route add default gw <gateway>
  ```

---

## 12. `host`
- **What it does**: DNS lookup utility.
- **Syntax**:
  ```bash
  host <domain>
  ```
- **Specify record type**:
  ```bash
  host -t <type> <domain>
  ```

---

## 13. `arp`
- **What it does**: Manipulates the ARP cache.
- **Syntax**:
  ```bash
  arp
  ```
- **Display IP addresses**:
  ```bash
  arp -n
  ```
- **Delete an entry**:
  ```bash
  arp -d <HWADDR>
  ```

---

## 14. `iwconfig`
- **What it does**: Configures wireless network interfaces.
- **Syntax**:
  ```bash
  iwconfig
  ```

---

## 15. `curl` & `wget`
### `curl`
- **What it does**: Downloads files from the internet.
- **Syntax**:
  ```bash
  curl -O <URL>
  ```

### `wget`
- **What it does**: Also downloads files from the internet.
- **Syntax**:
  ```bash
  wget <URL>
  ```

---

## 16. `mtr`
- **What it does**: Combines `ping` and `traceroute` for real-time network diagnostics.
- **Syntax**:
  ```bash
  mtr <destination>
  ```
- **Send report**:
  ```bash
  mtr --report <destination>
  ```

---

## 17. `whois`
- **What it does**: Retrieves information about domain ownership.
- **Syntax**:
  ```bash
  whois <domain>
  ```

---

## 18. `ifplugstatus`
- **What it does**: Checks if a network cable is connected.
- **Syntax**:
  ```bash
  ifplugstatus
  ```

---

## 19. `iftop`
- **What it does**: Monitors real-time network traffic.
- **Installation**:
  ```bash
  wget http://www.ex-parrot.com/pdw/iftop/download/iftop-0.17.tar.gz
  tar zxvf iftop-0.17.tar.gz
  cd iftop-0.17
  ./configure
  make
  make install
  ```
- **Run as root**:
  ```bash
  sudo iftop -I <interface>
  ```

---

## 20. `tcpdump`
- **What it does**: Captures and displays network traffic.
- **Syntax**:
  ```bash
  tcpdump -i <network_device>
  ```
- **Limit packet capture**:
  ```bash
  tcpdump -c 20 -i <network_device>
  ```
- **Save output to file**:
  ```bash
  tcpdump -w /path/to/file -i <network_device>
  ```
- **Read from file**:
  ```bash
  tcpdump -r /path/to/file
  ```
```

These are the network commands with their syntax and common variations, formatted in Markdown for easy reference.